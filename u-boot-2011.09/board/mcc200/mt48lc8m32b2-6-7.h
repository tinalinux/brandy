/*
 * board/mcc200/mt48lc8m32b2-6-7.h
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
 * Configuration Registers for the MT48LC8M32B2 SDRAM on the MPC5200 platform
 */

#define SDRAM_DDR	0		/* is SDR */

/* Settings for XLB = 132 MHz */

#define SDRAM_MODE	0x008d0000 /* CL-3 BURST-8 -> Mode Register MBAR + 0x0100 */
#define SDRAM_CONTROL	0x504f0000 /* Control Register MBAR + 0x0104 */
#define SDRAM_CONFIG1	0xc2222900 /* Delays between commands -> Configuration Register 1 MBAR + 0x0108 */
#define SDRAM_CONFIG2	0x88c70000 /* Delays between commands -> Configuration Register 2 MBAR + 0x010C */
