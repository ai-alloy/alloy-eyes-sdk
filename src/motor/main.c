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
#include "motor.h"

static const char *TAG = "MAIN";

int main(void)
{
	sysctl_pll_set_freq(SYSCTL_PLL0, 320000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL1, 160000000UL);
	sysctl_pll_set_freq(SYSCTL_PLL2, 45158400UL);
	uarths_init();

	plic_init();
    sysctl_enable_irq();
	
    LOGD(TAG, "MOTOR TEST");
	motor_io_mux();
	
	default_door();

	msleep(3000);

    while(1)
    {
		motor_control();
    }
}
