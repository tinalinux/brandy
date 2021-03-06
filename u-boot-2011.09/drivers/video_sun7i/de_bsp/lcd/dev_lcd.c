/*
 * drivers/video_sun7i/de_bsp/lcd/dev_lcd.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "lcd_source_interface.h"
#include "lcd_panel_cfg.h"

struct sunxi_lcd_drv g_lcd_drv;
extern int sunxi_disp_get_source_ops(struct sunxi_disp_source_ops *src_ops);
extern void LCD_set_panel_funs(void);

int lcd_init(void)
{
	sunxi_disp_get_source_ops(&g_lcd_drv.src_ops);
	LCD_set_panel_funs();

	return 0;
}



