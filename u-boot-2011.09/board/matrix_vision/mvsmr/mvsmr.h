/*
 * board/matrix_vision/mvsmr/mvsmr.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <pci.h>

extern void pci_mpc5xxx_init(struct pci_controller *);

#define FPGA_DIN	MPC5XXX_GPIO_SIMPLE_PSC3_0
#define FPGA_CCLK	MPC5XXX_GPIO_SIMPLE_PSC3_1
#define FPGA_DONE	MPC5XXX_GPIO_SIMPLE_PSC3_2
#define FPGA_CONFIG	MPC5XXX_GPIO_SIMPLE_PSC3_3
#define FPGA_STATUS	MPC5XXX_GPIO_SINT_PSC3_4
#define S_FPGA_DIN	MPC5XXX_GPIO_SINT_PSC3_5
#define S_FPGA_CCLK	MPC5XXX_GPIO_SIMPLE_PSC3_6
#define S_FPGA_DONE	MPC5XXX_GPIO_SIMPLE_PSC3_7
#define S_FPGA_CONFIG	MPC5XXX_GPIO_SINT_PSC3_8
#define S_FPGA_STATUS	MPC5XXX_GPIO_WKUP_PSC3_9

#define MAN_RST		MPC5XXX_GPIO_WKUP_PSC6_0
#define WD_TS		MPC5XXX_GPIO_WKUP_PSC6_1
#define WD_WDI		MPC5XXX_GPIO_SIMPLE_PSC6_2
#define COP_PRESENT	MPC5XXX_GPIO_SIMPLE_PSC6_3
#define SERVICE_MODE	MPC5XXX_GPIO_WKUP_6
#define FLASH_RBY	MPC5XXX_GPIO_WKUP_7
#define UART_EN1	MPC5XXX_GPIO_WKUP_PSC1_4
#define LAN_PRSNT	MPC5XXX_GPIO_WKUP_PSC2_4

#define SIMPLE_DDR	(FPGA_DIN | FPGA_CCLK | FPGA_CONFIG | WD_WDI |\
			 S_FPGA_CCLK)
#define SIMPLE_DVO	(FPGA_CONFIG)
#define SIMPLE_ODE	(FPGA_CONFIG)
#define SIMPLE_GPIOEN	(FPGA_DIN | FPGA_CCLK | FPGA_DONE | FPGA_CONFIG |\
			 S_FPGA_CCLK | S_FPGA_DONE | WD_WDI | COP_PRESENT)

#define SINT_ODE	0x1
#define SINT_DDR	0x3
#define SINT_DVO	0x1
#define SINT_INTEN	0
#define SINT_ITYPE	0
#define SINT_GPIOEN	(FPGA_STATUS | S_FPGA_DIN | S_FPGA_CONFIG)

#define WKUP_ODE	(MAN_RST | S_FPGA_STATUS)
#define WKUP_DIR	(MAN_RST | WD_TS | S_FPGA_STATUS)
#define WKUP_DO		(MAN_RST | WD_TS | S_FPGA_STATUS)
#define WKUP_EN		(MAN_RST | WD_TS | S_FPGA_STATUS | SERVICE_MODE |\
			 FLASH_RBY | UART_EN1 | LAN_PRSNT)
