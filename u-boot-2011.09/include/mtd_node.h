/*
 * include/mtd_node.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _NODE_INFO
#define _NODE_INFO

/*
 * Info we use to search for a flash node in DTB.
 */
struct node_info {
	const char *compat;	/* compatible string */
	int type;		/* mtd flash type */
};
#endif
