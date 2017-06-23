/*
 * (C) Copyright 2016
 *Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 *zhouhuacai <zhouhuacai@allwinnertech.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#include <common.h>
#include <asm/arch/base_pmu.h>
#include <power/sunxi/axp806_reg.h>
#include <asm/arch/platsmp.h>

int pmu_type;

#define dbg(format,arg...)	printf(format,##arg)

#define DUMMY_MODE		(1)

static int axp_probe(void)
{
	u8  pmu_type;

	if(axp_i2c_read(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_VERSION, &pmu_type))
	{
		printf("axp read error\n");

		return -1;
	}
	pmu_type &= 0xCF;
	if(pmu_type == 0x40)
	{
		/* pmu type AXP806 */
		printf("PMU: AXP806\n");
		return AXP806_ADDR;
	}
	else
	{
		printf("unknow PMU\n");
		return -1;
	}

}

static int axp806_set_dcdca(int vol)
{
	int      set_vol = vol;
	u8	 reg_value;
	u8	 tmp_step;
	if(set_vol > 0)
	{
		if(set_vol <= 1110)
		{
			if(set_vol < 600)
			{
				set_vol = 600;
			}
			tmp_step = (set_vol - 600)/10;
		}
		else
		{
			if(set_vol < 1120)
			{
				set_vol = 1120;
			}
			else if(set_vol > 1520)
			{
				set_vol = 1520;
			}

			tmp_step = (set_vol - 1120)/20 + 51;
		}
		if(axp_i2c_read(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_DCAOUT_VOL, &reg_value))
		{
			return -1;
		}
		reg_value &= 0x80;
		reg_value |= tmp_step;
		if(axp_i2c_write(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_DCAOUT_VOL, reg_value))
		{
			printf("sunxi pmu error : unable to set dcdc1\n");

			return -1;
		}
	}
	return 0;
}

static int axp806_set_dcdce(int vol)
{
	int ret = -1;
	unsigned char  vol_set;

	if(vol>=1600)
	{
		vol_set = (vol - 1500) / 100;
		vol_set +=45 ;
	}
	else
	{
		vol_set=(vol - 600)/20;
	}

	vol_set=(vol - 1100)/100;
	ret = axp_i2c_write(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_DCEOUT_VOL,vol_set);
	printf("PMU:Set DDR Vol %dmV %s.\n", vol,ret==0?"OK":"Fail");

	return ret;
}

int probe_power_key(void)
{
	return 0;
}


int set_ddr_voltage(int set_vol)
{
	if(pmu_type == AXP806_ADDR)
	{
		return axp806_set_dcdce(set_vol);
	}

	return 0;
}

int set_pll_voltage(int set_vol)
{
	if(pmu_type == AXP806_ADDR)
	{
		return axp806_set_dcdca(set_vol);
	}

	return 0;
}

static void sunxi_set_all_cpu_off(void)
{
	int off = 0, cluster = 0;
	cpu_power_switch_set(cluster, 1, off);
	cpu_power_switch_set(cluster, 2, off);
	cpu_power_switch_set(cluster, 3, off);
}

static inline void disable_pmu_pfm_mode(void)
{
	u8 val;
	axp_i2c_read(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_DCMOD_CTL2, &val);
	val |= (0x01 << 4);
	axp_i2c_write(CONFIG_SYS_I2C_SLAVE, BOOT_POWER806_DCMOD_CTL2, val);
}

int pmu_init(u8 power_mode)
{
	sunxi_set_all_cpu_off();
	if (power_mode == DUMMY_MODE)
	{
		pmu_type = 0;
	}
	else
	{
		i2c_init_cpus(CONFIG_SYS_I2C_SPEED, CONFIG_SYS_I2C_SLAVE);

		pmu_type = axp_probe();
	}
	if (AXP806_ADDR == pmu_type)
		disable_pmu_pfm_mode();

	return pmu_type;
}


