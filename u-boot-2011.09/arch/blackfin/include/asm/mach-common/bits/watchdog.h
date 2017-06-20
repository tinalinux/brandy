/*
 * arch/blackfin/include/asm/mach-common/bits/watchdog.h
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
 * Watchdog Masks
 */

#ifndef __BFIN_PERIPHERAL_WATCHDOG__
#define __BFIN_PERIPHERAL_WATCHDOG__

/* Watchdog Timer WDOG_CTL Register Masks */

#define WDEV			0x0006	/* event generated on roll over */
#define WDEV_RESET		0x0000	/* generate reset event on roll over */
#define WDEV_NMI		0x0002	/* generate NMI event on roll over */
#define WDEV_GPI		0x0004	/* generate GP IRQ on roll over */
#define WDEV_NONE		0x0006	/* no event on roll over */
#define WDEN			0x0FF0	/* enable watchdog */
#define WDDIS			0x0AD0	/* disable watchdog */
#define WDRO			0x8000	/* watchdog rolled over latch */

#endif
