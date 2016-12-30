/*
 * Copyright (C) 2016 Allwinner.
 * wangwei <wangwei@allwinnertech.com>
 *
 * SUNXI GPT Partition
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#include <common.h>
#include <mmc.h>
#include <sunxi_mbr.h>
#include <boot_type.h>
#include <u-boot/crc.h>
#include <gpt.h>
#include <sunxi_board.h>


static char gpt_buf[16*1024];
static int  gpt_status;
static int logic_offset = 0;


DECLARE_GLOBAL_DATA_PTR;

int char8_char16_compare(const char *char8, const efi_char16_t *char16, size_t char16_len)
{
	char char8_str[PARTNAME_SZ] = {0};
	int  i = 0;

	if(char16_len > PARTNAME_SZ)
	{
		return -1;
	}
	for(i = 0; i < char16_len; i++)
	{
		char8_str[i] = char16[i];
	}

	return strcmp(char8,char8_str);
}

int sunxi_partition_get_total_num(void)
{
	gpt_header     *gpt_head  = (gpt_header*)(gpt_buf+GPT_HAED_OFFSET);
	if(!gpt_status)
	{
		return 0;
	}

	return gpt_head->num_partition_entries;
}

int sunxi_partition_get_name(int part_index, char *buf)
{
	int			i;

	char   char8_name[PARTNAME_SZ] = {0};
	gpt_header     *gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	gpt_entry      *entry  = (gpt_entry*)(gpt_buf + GPT_ENTRY_OFFSET);

	if((!gpt_status) || (part_index >= gpt_head->num_partition_entries))
	{
		memset(buf, 0, 16);
		return 0;
	}

	for(i=0;i < PARTNAME_SZ; i++ )
	{
		char8_name[i] = (char)(entry[part_index].partition_name[i]);
	}
	strcpy(buf, char8_name);

	return 0;
}

uint sunxi_partition_get_offset(int part_index)
{
	gpt_header     *gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	gpt_entry       *entry  = (gpt_entry*)(gpt_buf + GPT_ENTRY_OFFSET);

	if((!gpt_status) || (part_index >= gpt_head->num_partition_entries))
	{
		return 0;
	}

	return (uint)(entry[part_index].starting_lba-logic_offset);
}

uint sunxi_partition_get_size(int part_index)
{
	gpt_entry      *entry  = (gpt_entry*)(gpt_buf + GPT_ENTRY_OFFSET);
	gpt_header     *gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	if((!gpt_status) || (part_index >= gpt_head->num_partition_entries))
	{
		return 0;
	}
	return (uint)(entry[part_index].ending_lba - entry[part_index].starting_lba);
}


int sunxi_partition_get_partno_byname(const char *part_name)
{
	int			   i;
	gpt_header     *gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	gpt_entry      *entry  = (gpt_entry*)(gpt_buf + GPT_ENTRY_OFFSET);

	if(!gpt_status)
	{
		return -1;
	}

	for(i=0;i<gpt_head->num_partition_entries;i++)
	{
		if(!char8_char16_compare(part_name, entry[i].partition_name, PARTNAME_SZ))
		{
			return i;
		}
	}

	return -1;
}

/* get the partition info, offset and size
 * input: partition name
 * output: part_offset and part_size (in byte)
 */
int sunxi_partition_get_info_byname(const char *part_name, uint *part_offset, uint *part_size)
{
	int			i;
	gpt_header  *gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	gpt_entry   *entry  = (gpt_entry*)(gpt_buf + GPT_ENTRY_OFFSET);

	if(!gpt_status)
	{
		return -1;
	}

	for(i=0;i<gpt_head->num_partition_entries;i++)
	{
		if(!char8_char16_compare(part_name, entry[i].partition_name, PARTNAME_SZ))
		{
			*part_offset =  (uint)(entry[i].starting_lba - logic_offset);
			*part_size = (uint)(entry[i].ending_lba - entry[i].starting_lba);
			return 0;
		}
	}

	return -1;
}

uint sunxi_partition_get_offset_byname(const char *part_name)
{
	uint part_offset = 0, part_size = 0;
	sunxi_partition_get_info_byname(part_name,&part_offset, &part_size);
	return part_offset;
}


uint sunxi_partition_get_size_byname(const char *part_name)
{
	uint part_offset = 0, part_size = 0;
	sunxi_partition_get_info_byname(part_name,&part_offset, &part_size);
	return part_size;
}



void *sunxi_partition_fetch_mbr(void)
{
	if(!gpt_status)
	{
		return NULL;
	}

	return gpt_buf;
}

int sunxi_partition_refresh(void *buf, uint bytes)
{
	if(!gpt_status)
	{
		return -1;
	}
	if(bytes != SUNXI_MBR_SIZE)
	{
		return -1;
	}

	memcpy(gpt_buf, buf, bytes);

	return 0;
}

int sunxi_partition_init(void)
{
	gpt_header     *gpt_head;
	int storage_type = 0;
	u32 calc_crc32 = 0;
	u32 backup_crc32 = 0;

	if(!sunxi_flash_read(0, SUNXI_MBR_SIZE >> 9, gpt_buf))
	{
		printf("read flash error\n");
		return 0;
	}
	storage_type = get_boot_storage_type();
	if(storage_type == STORAGE_EMMC || storage_type == STORAGE_EMMC3)
	{
		logic_offset = CONFIG_MMC_LOGICAL_OFFSET;
	}
	gpt_head  = (gpt_header*)(gpt_buf + GPT_HAED_OFFSET);
	if(gpt_head->signature == GPT_HEADER_SIGNATURE)
	{
		backup_crc32 = gpt_head->header_crc32;
		gpt_head->header_crc32 = 0;
		calc_crc32 = crc32(0,(const unsigned char *)gpt_head, sizeof(gpt_header)- GPT_RESERVED_SIZE);
		gpt_head->header_crc32 = backup_crc32;
		if(calc_crc32 == backup_crc32)
		{
			debug("gpt part count = %d\n", gpt_head->num_partition_entries);
			gpt_status = 1;
			//gd->lockflag = mbr->lockflag;
			return gpt_head->num_partition_entries;
		}
		else
		{
			printf("gpt crc error, 0x%x != 0x%x\n",backup_crc32, calc_crc32);
			gpt_status = 1;
			return gpt_head->num_partition_entries;
		}
	}
	else
	{
		printf("gpt magic error, %llx != %llx\n",gpt_head->signature, GPT_HEADER_SIGNATURE);
	}
	gpt_status = 0;
	return 0;
}

