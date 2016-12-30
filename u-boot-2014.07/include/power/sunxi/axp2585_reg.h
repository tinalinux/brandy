/*
 * Copyright (C) 2016 Allwinner.
 * wangwei <wangwei@allwinnertech.com>
 *
 * SUNXI AXP1506  Driver
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef   __AXP2585_REGS_H__
#define   __AXP2585_REGS_H__

#define   AXP2585_ADDR              (0x36)

#define   PMU_POWER_SOURCE_STATUS   (0x00)
#define   PMU_STARTUP_SOURCE        (0x02)
#define   PMU_IC_TYPE               (0x03)
#define   PMU_DATA_BUFFER0          (0x05)
#define   PMU_DATA_BUFFER1          (0x06)
#define   PMU_RESTART_POWOFF        (0x28)
#define   PMU_BAT_VOL               (0x78)
#define   PMU_BAT_PERCENTAGE        (0xB9)
#define   PMU_ADDR_EXTENSION        (0xff)

#endif /* __AXP1506_REGS_H__ */

