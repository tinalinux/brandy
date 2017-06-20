/*
 * include/bedbug/type.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _TYPE_BEDBUG_H
#define _TYPE_BEDBUG_H

/* Supporting routines */
int bedbug_puts (const char *);
void bedbug_init (void);
void bedbug860_init (void);
void do_bedbug_breakpoint (struct pt_regs *);
void bedbug_main_loop (unsigned long, struct pt_regs *);


typedef struct {
	int hw_debug_enabled;
	int stopped;
	int current_bp;
	struct pt_regs *regs;

	void (*do_break) (cmd_tbl_t *, int, int, char * const []);
	void (*break_isr) (struct pt_regs *);
	int (*find_empty) (void);
	int (*set) (int, unsigned long);
	int (*clear) (int);
} CPU_DEBUG_CTX;


#endif /* _TYPE_BEDBUG_H  */
