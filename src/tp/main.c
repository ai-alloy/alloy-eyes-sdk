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
#include "board_config.h"
#ifdef  USE_RTP_PANEL
//#include "tp_cal.h"
#include "tp_driver.h"
#endif
#ifdef  SUPPORT_CTP_CST0
#include "cst826.h"
#endif

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

#ifdef  USE_RTP_PANEL
static void rtp_data_handle()
{
	get_rtp_data();
}
#endif

#ifdef  SUPPORT_CTP_CST0
static void ctp_data_handle()
{
	cpt_event_t cpt_event;

	cpt_cst0_get_data(&cpt_event);
}
#endif

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, PLL0_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL1, PLL1_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL2, PLL2_OUTPUT_FREQ);
    uarths_init();
	
	io_mux_init();
    io_set_power();

    LOGD(TAG, "LCD RTP TEST");

#ifdef  USE_RTP_PANEL
	io_init_tp();	
    lcd_init();
#endif

#ifdef  USE_CTP_PANEL
#ifdef  SUPPORT_CTP_CST0
	ctp_hynitron_cst0_init();
#endif
	lcd_init_ex();
#endif

	lcd_set_direction_ex(DIR_XY_RLUD);	
    lcd_clear(RED);
	lcd_draw_string(50, 100, "Hello,Alloy eyes!", BLUE);
	while(1)
	{
	#ifdef  USE_RTP_PANEL
		rtp_data_handle();
	#endif
	#ifdef  SUPPORT_CTP_CST0
		ctp_data_handle();
	#endif
		msleep(10);
	}

    return 0;
}

