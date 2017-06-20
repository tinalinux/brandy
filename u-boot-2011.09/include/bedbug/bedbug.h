/*
 * include/bedbug/bedbug.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/* $Id$ */

#ifndef _BEDBUG_H
#define _BEDBUG_H

#ifndef NULL
#define NULL	0
#endif

#define _USE_PROTOTYPES

#ifndef isblank
#define isblank(c) isspace((int)(c))
#endif

#ifndef __P
#if defined(_USE_PROTOTYPES) && (defined(__STDC__) || defined(__cplusplus))
#define __P(protos)	protos		/* full-blown ANSI C */
#else
#define __P(protos)	()		/* traditional C preprocessor */
#endif
#endif

#endif /* _BEDBUG_H */


/*
 * Copyright (c) 2001 William L. Pitts
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are freely
 * permitted provided that the above copyright notice and this
 * paragraph and the following disclaimer are duplicated in all
 * such forms.
 *
 * This software is provided "AS IS" and without any express or
 * implied warranties, including, without limitation, the implied
 * warranties of merchantability and fitness for a particular
 * purpose.
 */
