/*
 * arch/blackfin/include/asm/mach-common/bits/trace.h
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
 * Trace Unit Masks
 */

#ifndef __BFIN_PERIPHERAL_TRACE__
#define __BFIN_PERIPHERAL_TRACE__

/* Trace Buffer Control (TBUFCTL) Register Masks */
#define TBUFPWR       0x00000001
#define TBUFEN        0x00000002
#define TBUFOVF       0x00000004
#define CMPLB_SINGLE  0x00000008
#define CMPLP_DOUBLE  0x00000010
#define CMPLB         (CMPLB_SINGLE | CMPLP_DOUBLE)

/* Trace Buffer Status (TBUFSTAT) Register Masks */
#define TBUFCNT       0x0000001F

#endif
