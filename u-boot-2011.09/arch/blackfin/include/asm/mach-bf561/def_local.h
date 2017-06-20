/*
 * arch/blackfin/include/asm/mach-bf561/def_local.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#define SWRST SICA_SWRST
#define SYSCR SICA_SYSCR
#define bfin_write_SWRST(val) bfin_write_SICA_SWRST(val)
#define bfin_write_SYSCR(val) bfin_write_SICA_SYSCR(val)

#define WDOG_CNT WDOGA_CNT
#define WDOG_CTL WDOGA_CTL
#define bfin_write_WDOG_CNT(val) bfin_write_WDOGA_CNT(val)
#define bfin_write_WDOG_CTL(val) bfin_write_WDOGA_CTL(val)
#define bfin_write_WDOG_STAT(val) bfin_write_WDOGA_STAT(val)

#include "gpio.h"
#include "portmux.h"
#include "ports.h"

#define BF561_FAMILY 1	/* Linux glue */
