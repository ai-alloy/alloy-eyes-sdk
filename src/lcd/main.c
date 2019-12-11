#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "dvp.h"
#include "fpioa.h"
#include "lcd.h"
#include "plic.h"
#include "sysctl.h"
#include "uarths.h"
#include "st7789.h"
#include "utils.h"
#include "syslog.h"
#include "sleep.h"
#include "gpiohs.h"

#define PLL0_OUTPUT_FREQ 400000000UL
#define PLL1_OUTPUT_FREQ 300000000UL
#define PLL2_OUTPUT_FREQ 45158400UL

static const char *TAG = "MAIN";

static void io_mux_init(void)
{
    /* Init SPI IO map and function settings */
    fpioa_set_function(37, FUNC_GPIOHS0 + RST_GPIONUM);
    fpioa_set_function(38, FUNC_GPIOHS0 + DCX_GPIONUM);
    fpioa_set_function(36, FUNC_SPI0_SS3);
    fpioa_set_function(39, FUNC_SPI0_SCLK);
    sysctl_set_spi0_dvp_data(1);
}

static void io_set_power(void)
{
    sysctl_set_power_mode(SYSCTL_POWER_BANK6, SYSCTL_POWER_V18);
    sysctl_set_power_mode(SYSCTL_POWER_BANK7, SYSCTL_POWER_V18);
}

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, PLL0_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL1, PLL1_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL2, PLL2_OUTPUT_FREQ);
    uarths_init();
	
	io_mux_init();
    io_set_power();
	
    LOGD(TAG, "LCD RTP TEST");
    lcd_init();
	lcd_set_direction_ex(DIR_XY_RLUD);	
    lcd_clear(RED);
	lcd_draw_string(50, 100, "Hello,Alloy eyes!", BLUE);
	while(1)
	{
		msleep(10);
	}

    return 0;
}

