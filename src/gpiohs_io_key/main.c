#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "syslog.h"
#include "gpio.h"
#include "uarths.h"
#include "io_key.h"

static const char *TAG = "GPIOHS";

static void io_key_handle()
{
	key_event_t keyEvent;

	if(0 != key_detect(&keyEvent)){
		return;
	}

	LOGI(TAG,"keyEvent key_num:%d",keyEvent.key_num);	
	LOGI(TAG,"keyEvent press:%d",keyEvent.press);	
}

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, 320000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL1, 160000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL2, 45158400UL);
	uarths_init();	

	LOGD(TAG, "gpiohs-io-key demo...");
	
    gpio_init();
	key_init();

    while (1)
    {
    	io_key_handle();
    }
	
    return 0;
}
