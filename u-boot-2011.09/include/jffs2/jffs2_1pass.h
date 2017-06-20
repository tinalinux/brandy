/*
 * include/jffs2/jffs2_1pass.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
u32 jffs2_1pass_ls(struct part_info *part,const char *fname);
u32 jffs2_1pass_load(char *dest, struct part_info *part,const char *fname);
u32 jffs2_1pass_info(struct part_info *part);
