/*
 * arch/sh/include/asm/cache.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_SH_CACHE_H
#define __ASM_SH_CACHE_H

#if defined(CONFIG_SH4) || defined(CONFIG_SH4A)

int cache_control(unsigned int cmd);

#define L1_CACHE_BYTES 32
struct __large_struct { unsigned long buf[100]; };
#define __m(x) (*(struct __large_struct *)(x))

void dcache_wback_range(u32 start, u32 end)
{
	u32 v;

	start &= ~(L1_CACHE_BYTES - 1);
	for (v = start; v < end; v += L1_CACHE_BYTES) {
		asm volatile ("ocbwb     %0" :	/* no output */
			      : "m" (__m(v)));
	}
}

void dcache_invalid_range(u32 start, u32 end)
{
	u32 v;

	start &= ~(L1_CACHE_BYTES - 1);
	for (v = start; v < end; v += L1_CACHE_BYTES) {
		asm volatile ("ocbi     %0" :	/* no output */
			      : "m" (__m(v)));
	}
}
#endif /* CONFIG_SH4 || CONFIG_SH4A */

#endif	/* __ASM_SH_CACHE_H */
