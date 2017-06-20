/*
 * drivers/mmc/mmc_def.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __MMC_DEF__
#define __MMC_DEF__

//#define SUNXI_MMCDBG

#ifdef SUNXI_MMCDBG
#define MMCINFO(fmt...)	tick_printf("[mmc]: "fmt)//err and info
#define MMCDBG(fmt...)	tick_printf("[mmc]: "fmt)//dbg
#define MMCMSG(fmt...)	tick_printf(fmt)//data or register and so on
#else
#define MMCINFO(fmt...)	tick_printf("[mmc]: "fmt)
#define MMCDBG(fmt...)
#define MMCMSG(fmt...)
#endif


#define DRIVER_VER  "2016-03-24 19:30:15"

//#define TUNING_LEN		(1)//The address which store the tuninng pattern
//#define TUNING_ADD		(38192-TUNING_LEN)//The address which store the tuninng pattern
#define TUNING_LEN		(10)//The length of the tuninng pattern
#define TUNING_ADD		(38192-2-TUNING_LEN)//The address which store the tuninng pattern
#define REPEAT_TIMES	(30)
#define SAMPLE_MODE 	(2)
#define AUTO_SAMPLE_MODE (2)


//secure storage relate
#define MAX_SECURE_STORAGE_MAX_ITEM		32
#define SDMMC_SECURE_STORAGE_START_ADD	(6*1024*1024/512)//6M
#define SDMMC_ITEM_SIZE					(4*1024/512)//4K




#endif
