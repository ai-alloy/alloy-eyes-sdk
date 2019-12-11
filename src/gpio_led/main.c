#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpio.h"
#include "uarths.h"
#include "syslog.h"
#include "board_config.h"

static const char *TAG = "GPIO";

#define LED_R_FUNC_GPIO_NUM	1

static void io_mux_init(void)
{
	fpioa_set_function(LED_R_PIN_NUM, FUNC_GPIO0 + LED_R_FUNC_GPIO_NUM);
}

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, 320000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL1, 160000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL2, 45158400UL);
	uarths_init();	

	LOGD(TAG, "gpio_led demo...");
	
	io_mux_init();
    gpio_init();
    gpio_set_drive_mode(LED_R_FUNC_GPIO_NUM, GPIO_DM_OUTPUT);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpio_set_pin(LED_R_FUNC_GPIO_NUM, value);
    while (1)
    {
        sleep(1);
        gpio_set_pin(LED_R_FUNC_GPIO_NUM, value = !value);
    }
    return 0;
}
