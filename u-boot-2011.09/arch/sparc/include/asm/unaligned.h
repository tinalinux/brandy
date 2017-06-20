/*
 * arch/sparc/include/asm/unaligned.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_SPARC_UNALIGNED_H
#define _ASM_SPARC_UNALIGNED_H

/*
 * The SPARC can not do unaligned accesses, it must be split into multiple
 * byte accesses. The SPARC is in big endian mode.
 */
#include <asm-generic/unaligned.h>

#endif	/* _ASM_SPARC_UNALIGNED_H */
