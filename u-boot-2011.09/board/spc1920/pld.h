/*
 * board/spc1920/pld.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __PLD_H__
#define __PLD_H__

typedef struct spc1920_pld {
	uchar com1_en;
	uchar dsp_reset;
	uchar dsp_hpi_on;
	uchar superv_mode;
	uchar codec_dsp_power_en;
	uchar clk3_select;
	uchar clk4_select;
} spc1920_pld_t;

#endif /* __PLD_H__ */
