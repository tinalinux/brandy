/*
 * include/sata.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __SATA_H__
#define __SATA_H__

int init_sata(int dev);
int scan_sata(int dev);
ulong sata_read(int dev, ulong blknr, ulong blkcnt, void *buffer);
ulong sata_write(int dev, ulong blknr, ulong blkcnt, const void *buffer);

int sata_initialize(void);
int __sata_initialize(void);

#endif
