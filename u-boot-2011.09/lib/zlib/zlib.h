/*
 * lib/zlib/zlib.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/* Glue between u-boot and upstream zlib */
#ifndef __GLUE_ZLIB_H__
#define __GLUE_ZLIB_H__

#include <common.h>
#include <compiler.h>
#include <asm/unaligned.h>
#include <watchdog.h>
#include "u-boot/zlib.h"

/* avoid conflicts */
#undef OFF
#undef ASMINF
#undef POSTINC
#undef NO_GZIP
#define GUNZIP
#undef STDC
#undef NO_ERRNO_H

#endif
