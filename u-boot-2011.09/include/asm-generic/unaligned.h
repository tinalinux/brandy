/*
 * include/asm-generic/unaligned.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _GENERIC_UNALIGNED_H
#define _GENERIC_UNALIGNED_H

#include <asm/byteorder.h>

#include <linux/unaligned/le_byteshift.h>
#include <linux/unaligned/be_byteshift.h>
#include <linux/unaligned/generic.h>

/*
 * Select endianness
 */
#if defined(__LITTLE_ENDIAN)
#define get_unaligned	__get_unaligned_le
#define put_unaligned	__put_unaligned_le
#elif defined(__BIG_ENDIAN)
#define get_unaligned	__get_unaligned_be
#define put_unaligned	__put_unaligned_be
#else
#error invalid endian
#endif

#endif
