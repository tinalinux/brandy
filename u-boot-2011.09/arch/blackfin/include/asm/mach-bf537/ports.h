/*
 * arch/blackfin/include/asm/mach-bf537/ports.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*
 * Port Masks
 */

#ifndef __BFIN_PERIPHERAL_PORT__
#define __BFIN_PERIPHERAL_PORT__

/* PORT_MUX Masks */
#define PJSE			0x0001
#define PJCE_MASK		0x0006
#define PJCE_SPORT		0x0000
#define PJCE_CAN		0x0001
#define PJCE_SPI		0x0002
#define PFDE			0x0008
#define PFTE			0x0010
#define PFS6E			0x0020
#define PFS5E			0x0040
#define PFS4E			0x0080
#define PFFE			0x0100
#define PGSE			0x0200
#define PGRE			0x0400
#define PGTE			0x0800

#include "../mach-common/bits/ports-f.h"
#include "../mach-common/bits/ports-g.h"
#include "../mach-common/bits/ports-h.h"

#endif
