/*
 * board/fads/lamp.c
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

#ifndef CONFIG_ADS /* Old ADS has not got any user-controllable LED */

#include <common.h>

void
signal_delay(unsigned int n)
{
  while (n--);
}

void
signal_on(void)
{
  *((volatile uint *)BCSR4) &= ~(1<<(31-3)); /* led on */
}

void
signal_off(void)
{
  *((volatile uint *)BCSR4) |= (1<<(31-3)); /* led off */
}

void
slow_blink(unsigned int n)
{
  while (n--) {
    signal_on();
    signal_delay(0x00400000);
    signal_off();
    signal_delay(0x00400000);
  }
}

void
fast_blink(unsigned int n)
{
  while (n--) {
    signal_on();
    signal_delay(0x00100000);
    signal_off();
    signal_delay(0x00100000);
  }
}

#endif /* !CONFIG_ADS */
