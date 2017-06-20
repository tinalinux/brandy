/*
 * include/errno.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ERRNO_H

#include <asm-generic/errno.h>

extern int errno;

#define __set_errno(val) do { errno = val; } while (0)

#endif /* _ERRNO_H */
