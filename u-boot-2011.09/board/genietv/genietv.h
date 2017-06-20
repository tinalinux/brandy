/*
 * board/genietv/genietv.h
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
 * The GENIETV is using the following physical memorymap (copied from
 * the FADS configuration):
 *
 * ff020000 -> ff02ffff : pcmcia
 * ff010000 -> ff01ffff : BCSR       connected to CS1, setup by 8xxROM
 * ff000000 -> ff00ffff : IMAP       internal in the cpu
 * 02800000 -> 0287ffff : flash      connected to CS0
 * 00000000 -> nnnnnnnn : sdram      setup by U-Boot
 *
 * CS pins are connected as follows:
 *
 * CS0 -512Kb boot flash
 * CS1 - SDRAM #1
 * CS2 - SDRAM #2
 * CS3 - Flash #1
 * CS4 - Flash #2
 * CS5 - LON (if present)
 * CS6 - PCMCIA #1
 * CS7 - PCMCIA #2
 *
 * Ports are configured as follows:
 *
 * PA7 - SDRAM banks enable
 */
