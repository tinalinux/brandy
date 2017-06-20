/*
 * include/linux/poison.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _LINUX_POISON_H
#define _LINUX_POISON_H

/********** include/linux/list.h **********/
/*
 * used to verify that nobody uses non-initialized list entries.
 */
#define LIST_POISON1  ((void *) 0x0)
#define LIST_POISON2  ((void *) 0x0)

#endif
