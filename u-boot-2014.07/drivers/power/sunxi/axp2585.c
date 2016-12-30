/*
 * Copyright (C) 2016 Allwinner.
 * wangwei <wangwei@allwinnertech.com>
 *
 * SUNXI AXP1506  Driver
 *
 * SPDX-License-Identifier: GPL-2.0+
 */


#include <common.h>
#include <power/sunxi/axp2585_reg.h>
#include <power/sunxi/axp.h>
#include <power/sunxi/pmu.h>

extern int axp2585_set_supply_status(int vol_name, int vol_value, int onoff);
extern int axp2585_set_supply_status_byname(char *vol_name, int vol_value, int onoff);
extern int axp2585_probe_supply_status(int vol_name, int vol_value, int onoff);
extern int axp2585_probe_supply_status_byname(char *vol_name);


int axp2585_probe(void)
{
	u8    pmu_type;

	if(axp_i2c_write(AXP2585_ADDR,PMU_ADDR_EXTENSION, 0x40))
	{
		printf("axp2585 write 0xff error\n");
		return -1;
	}
	if(axp_i2c_read(AXP2585_ADDR,PMU_IC_TYPE, &pmu_type))
	{
		printf("axp2585 read error\n");
		return -1;
	}
	printf("pmu_type = %x\n",pmu_type);
	pmu_type &= 0xCF;
	if(pmu_type == 0x43)
	{
		/* pmu type AXP2585 */
		tick_printf("PMU: AXP2585\n");
		return 0;
	}
	return -1;
}

int axp2585_set_coulombmeter_onoff(int onoff)
{
	return 0;
}

int axp2585_set_charge_control(void)
{
	return 0;
}

int axp2585_probe_battery_exist(void)
{
	u8 reg_value;

	if(axp_i2c_read(AXP2585_ADDR, PMU_POWER_SOURCE_STATUS, &reg_value))
	{
		return -1;
	}
	//bit2 -- 0:does't have detected 1: have detected
	if((reg_value & (1<<2)))
	{
		//bit4 -- 0:battery not connected 1: battery connected
		return (reg_value & (1<<4));
	}
	else
	{
		return 0;
	}
}

int axp2585_probe_battery_ratio(void)
{
	u8 reg_value;

	if(axp_i2c_read(AXP2585_ADDR, PMU_BAT_PERCENTAGE, &reg_value))
	{
		return -1;
	}

	//bit7-- 1:valid 0:invalid
	if(reg_value&(1<<7))
	{
		reg_value = reg_value & 0x7f;
	}
	else
	{
		reg_value = 0;
	}

	return reg_value;
}

int axp2585_probe_power_status(void)
{
	u8 reg_value;

	if(axp_i2c_read(AXP2585_ADDR, PMU_POWER_SOURCE_STATUS, &reg_value))
	{
		return -1;
	}

	if(reg_value & 0x1)		//AC in exist
	{
		return AXP_DCIN_EXIST;
	}
	return -1;

}

int axp2585_probe_battery_vol(void)
{
	u8 reg_value;
	int bat_vol;
	if(axp_i2c_read(AXP2585_ADDR, PMU_BAT_VOL, &reg_value))
	{
		return -1;
	}
	//check spec: 6.7 ADC
	bat_vol = reg_value * 12;
	bat_vol /= 10;

	return bat_vol;
}

int axp2585_probe_key(void)
{
    return 0;
}

int axp2585_probe_pre_sys_mode(void)
{
	u8  reg_value;
	if(axp_i2c_read(AXP2585_ADDR, PMU_DATA_BUFFER0, &reg_value))
	{
		return -1;
	}

	return reg_value;
}

int axp2585_set_next_sys_mode(int data)
{
	if(axp_i2c_write(AXP2585_ADDR, PMU_DATA_BUFFER0, (u8)data))
	{
		return -1;
	}
	return 0;
}

int axp2585_probe_this_poweron_cause(void)
{
	uchar   reg_value;
	if(axp_i2c_read(AXP2585_ADDR, PMU_STARTUP_SOURCE, &reg_value))
	{
		return -1;
	}
	if(reg_value&(1<<3)) //startup by PWRON press
	{
		return 0;
	}
	else if(reg_value&(1<<4)) //startup by VACIN
	{
		return 1;
	}
	return reg_value & 0x01;
}

int axp2585_set_power_off(void)
{
	u8 reg_addr;
	u8  reg_value;
	printf("axp2585_set_power_off\n");
	reg_addr = PMU_RESTART_POWOFF;
	if(axp_i2c_read(AXP2585_ADDR, reg_addr, &reg_value))
	{
		printf("axp2585_set_power_off read error\n");
		return -1;
	}
	reg_value |= 1 << 6;
	if(axp_i2c_write(AXP2585_ADDR, reg_addr, reg_value))
	{
		return -1;
	}
	printf("axp2585_set_power_off failed\n");
	return 0;
}

int axp2585_set_power_onoff_vol(int set_vol, int stage)
{
	return 0;
}
int axp2585_set_charge_current(int current)
{
	return 0;
}
int axp2585_probe_charge_current(void)
{
	return 0;
}
int axp2585_set_vbus_cur_limit(int current)
{
	return 0;
}

int axp2585_probe_vbus_cur_limit(void)
{
	return  0;
}
int axp2585_set_vbus_vol_limit(int vol)
{
	return 0;
}
int axp2585_probe_int_pending(uchar *addr)
{

	return 0;
}

int axp2585_probe_int_enable(uchar *addr)
{

	return 0;

}

int axp2585_set_int_enable(uchar *addr)
{

	return 0;
}

sunxi_axp_module_init("axp2585", SUNXI_AXP_2585);




