/*
 * lib/zlib/zlib.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*
 * This file is derived from various .h and .c files from the zlib-1.2.3
 * distribution by Jean-loup Gailly and Mark Adler, with some additions
 * by Paul Mackerras to aid in implementing Deflate compression and
 * decompression for PPP packets.  See zlib.h for conditions of
 * distribution and use.
 *
 * Changes that have been made include:
 * - changed functions not used outside this file to "local"
 * - added minCompression parameter to deflateInit2
 * - added Z_PACKET_FLUSH (see zlib.h for details)
 * - added inflateIncomp
 */

#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"
#include "inffixed.h"
#include "inffast.c"
#include "inftrees.c"
#include "inflate.c"
#include "zutil.c"
#include "adler32.c"
