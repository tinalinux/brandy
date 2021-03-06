/*
 * arch/m68k/include/asm/unaligned.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_M68K_UNALIGNED_H
#define _ASM_M68K_UNALIGNED_H

#ifdef CONFIG_COLDFIRE
#include <linux/unaligned/be_byteshift.h>
#else
#include <linux/unaligned/access_ok.h>
#endif

#include <linux/unaligned/generic.h>

#define get_unaligned	__get_unaligned_be
#define put_unaligned	__put_unaligned_be

#endif /* _ASM_M68K_UNALIGNED_H */
