/*
 * arch/blackfin/include/asm/mach-bf548/BF547_cdef.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/* DO NOT EDIT THIS FILE
 * Automatically generated by generate-cdef-headers.xsl
 * DO NOT EDIT THIS FILE
 */

#ifndef __BFIN_CDEF_ADSP_BF547_proc__
#define __BFIN_CDEF_ADSP_BF547_proc__

#include "../mach-common/ADSP-EDN-core_cdef.h"

#include "ADSP-EDN-BF547-extended_cdef.h"

#define bfin_read_CHIPID()             bfin_read32(CHIPID)
#define bfin_write_CHIPID(val)         bfin_write32(CHIPID, val)
#define bfin_read_SWRST()              bfin_read16(SWRST)
#define bfin_write_SWRST(val)          bfin_write16(SWRST, val)
#define bfin_read_SYSCR()              bfin_read16(SYSCR)
#define bfin_write_SYSCR(val)          bfin_write16(SYSCR, val)

#endif /* __BFIN_CDEF_ADSP_BF547_proc__ */
