/*
 * board/evb64260/i2c.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __I2C_H__
#define __I2C_H__

/* function declarations */
uchar i2c_read(uchar, unsigned int, int, uchar*, int);

#endif
