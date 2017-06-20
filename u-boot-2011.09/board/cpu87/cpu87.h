/*
 * board/cpu87/cpu87.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __BOARD_CPU87__
#define __BOARD_CPU87__

#include <config.h>

#define REG8(x)			(*(volatile unsigned char *)(x))

/* CPU86 register definitions */
#define CPU86_VME_EAC		REG8(CONFIG_SYS_BCRS_BASE + 0x00)
#define CPU86_VME_SAC		REG8(CONFIG_SYS_BCRS_BASE + 0x01)
#define CPU86_VME_MAC		REG8(CONFIG_SYS_BCRS_BASE + 0x02)
#define CPU86_BCR		REG8(CONFIG_SYS_BCRS_BASE + 0x03)
#define CPU86_BSR		REG8(CONFIG_SYS_BCRS_BASE + 0x04)
#define CPU86_WDOG_RPORT	REG8(CONFIG_SYS_BCRS_BASE + 0x05)
#define CPU86_MBOX_IRQ		REG8(CONFIG_SYS_BCRS_BASE + 0x04)
#define CPU86_REV		REG8(CONFIG_SYS_BCRS_BASE + 0x07)
#define CPU86_VME_IRQMASK	REG8(CONFIG_SYS_BCRS_BASE + 0x80)
#define CPU86_VME_IRQSTATUS	REG8(CONFIG_SYS_BCRS_BASE + 0x81)
#define CPU86_LOCAL_IRQMASK	REG8(CONFIG_SYS_BCRS_BASE + 0x82)
#define CPU86_LOCAL_IRQSTATUS	REG8(CONFIG_SYS_BCRS_BASE + 0x83)
#define CPU86_PMCL_IRQSTATUS	REG8(CONFIG_SYS_BCRS_BASE + 0x84)

/* Board Control Register bits */
#define CPU86_BCR_FWPT		0x01
#define CPU86_BCR_FWRE		0x02

#endif /* __BOARD_CPU87__ */
