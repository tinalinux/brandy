/*
 * arch/sh/include/asm/processor.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_SH_PROCESSOR_H_
#define _ASM_SH_PROCESSOR_H_
#if defined(CONFIG_SH2) || \
	defined (CONFIG_SH2A)
# include <asm/cpu_sh2.h>
#elif defined (CONFIG_SH3)
# include <asm/cpu_sh3.h>
#elif defined (CONFIG_SH4) || \
	defined (CONFIG_SH4A)
# include <asm/cpu_sh4.h>
#endif
#endif
