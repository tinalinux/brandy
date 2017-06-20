/*
 * arch/m68k/include/asm/processor.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_M68K_PROCESSOR_H
#define __ASM_M68K_PROCESSOR_H

#include <asm/ptrace.h>
#include <asm/types.h>

#define _GLOBAL(n)\
	.globl n;\
n:

/* Macros for setting and retrieving special purpose registers */
#define setvbr(v)	asm volatile("movec %0,%%VBR" : : "r" (v))

#ifndef __ASSEMBLY__

#endif /* ifndef ASSEMBLY*/

#endif /* __ASM_M68K_PROCESSOR_H */
