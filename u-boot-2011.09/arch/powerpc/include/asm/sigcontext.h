/*
 * arch/powerpc/include/asm/sigcontext.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_PPC_SIGCONTEXT_H
#define _ASM_PPC_SIGCONTEXT_H

#include <asm/ptrace.h>


struct sigcontext_struct {
	unsigned long	_unused[4];
	int		signal;
	unsigned long	handler;
	unsigned long	oldmask;
	struct pt_regs	*regs;
};

#endif
