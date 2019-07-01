#include <stdio.h>
#include <syslog.h>
#include <timer.h>
#include <plic.h>
#include <sysctl.h>
#include <fpioa.h>
#include "gpio.h"
#include "gpiohs.h"
#include "uarths.h"
#include "sleep.h"
#include "sd_spi.h"
#include "flash_spi.h"

static const char *TAG = "MAIN";

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, 320000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL1, 160000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL2, 45158400UL);
	uarths_init();

	plic_init();
    sysctl_enable_irq();

	LOGI(TAG,"");
	LOGI(TAG,"========SD CARD(SPI) TEST=======");
	if(0 == sdcard_init()){
		sdcard_test();
	}
	LOGI(TAG,"========SD CARD(SPI) END=======");
	
	LOGI(TAG,"");

	LOGI(TAG,"========FLASH(SPI) TEST=======");
	if(0 == flash_init_ex()){
		flash_test();
	}
	LOGI(TAG,"========FLASH(SPI) END=======");
	
    while(1);
}

