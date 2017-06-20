/*
 * arch/powerpc/cpu/mpc512x/asm-offsets.h
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
 * needed for arch/powerpc/cpu/mpc512x/start.S
 *
 * These should be auto-generated
 */
#define LPCS0AW			0x0024
#define SRAMBAR			0x00C4
#define SWCRR			0x0904
#define LPC_OFFSET		0x10000
#define CS0_CONFIG		0x00000
#define CS_CTRL			0x00020
#define CS_CTRL_ME		0x01000000	/* CS Master Enable bit */

#define EXC_OFF_SYS_RESET	0x0100
#define	_START_OFFSET		EXC_OFF_SYS_RESET
