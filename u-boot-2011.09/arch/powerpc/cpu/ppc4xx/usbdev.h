/*
 * arch/powerpc/cpu/ppc4xx/usbdev.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <config.h>

/*Common Registers*/
#define USB2D0_INTRIN_16   (CONFIG_SYS_USB_DEVICE | 0x100)
#define USB2D0_POWER_8     (CONFIG_SYS_USB_DEVICE | 0x102)
#define USB2D0_FADDR_8     (CONFIG_SYS_USB_DEVICE | 0x103)
#define USB2D0_INTRINE_16  (CONFIG_SYS_USB_DEVICE | 0x104)
#define USB2D0_INTROUT_16  (CONFIG_SYS_USB_DEVICE | 0x106)
#define USB2D0_INTRUSBE_8  (CONFIG_SYS_USB_DEVICE | 0x108)
#define USB2D0_INTRUSB_8   (CONFIG_SYS_USB_DEVICE | 0x109)
#define USB2D0_INTROUTE_16 (CONFIG_SYS_USB_DEVICE | 0x10a)
#define USB2D0_TSTMODE_8   (CONFIG_SYS_USB_DEVICE | 0x10c)
#define USB2D0_INDEX_8     (CONFIG_SYS_USB_DEVICE | 0x10d)
#define USB2D0_FRAME_16    (CONFIG_SYS_USB_DEVICE | 0x10e)

/*Indexed Registers*/
#define USB2D0_INCSR0_8    (CONFIG_SYS_USB_DEVICE | 0x110)
#define USB2D0_INCSR_16    (CONFIG_SYS_USB_DEVICE | 0x110)
#define USB2D0_INMAXP_16   (CONFIG_SYS_USB_DEVICE | 0x112)
#define USB2D0_OUTCSR_16   (CONFIG_SYS_USB_DEVICE | 0x114)
#define USB2D0_OUTMAXP_16  (CONFIG_SYS_USB_DEVICE | 0x116)
#define USB2D0_OUTCOUNT0_8 (CONFIG_SYS_USB_DEVICE | 0x11a)
#define USB2D0_OUTCOUNT_16 (CONFIG_SYS_USB_DEVICE | 0x11a)

/*FIFOs*/
#define USB2D0_FIFO_0 (CONFIG_SYS_USB_DEVICE | 0x120)
#define USB2D0_FIFO_1 (CONFIG_SYS_USB_DEVICE | 0x124)
#define USB2D0_FIFO_2 (CONFIG_SYS_USB_DEVICE | 0x128)
#define USB2D0_FIFO_3 (CONFIG_SYS_USB_DEVICE | 0x12c)

void usb_dev_init(void);
