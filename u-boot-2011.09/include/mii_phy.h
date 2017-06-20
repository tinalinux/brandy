/*
 * include/mii_phy.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _MII_PHY_H_
#define _MII_PHY_H_

void mii_discover_phy(void);
unsigned short mii_phy_read(unsigned short reg);
void mii_phy_write(unsigned short reg, unsigned short val);

#endif
