/*
 * fs/aw_fs/option/unicode.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "../ff.h"

#if _USE_LFN != 0

#if   _CODE_PAGE == 932
#include "cc932.c"
#elif _CODE_PAGE == 936
#include "cc936.c"
#elif _CODE_PAGE == 949
#include "cc949.c"
#elif _CODE_PAGE == 950
#include "cc950.c"
#else
#include "ccsbcs.c"
#endif

#endif
