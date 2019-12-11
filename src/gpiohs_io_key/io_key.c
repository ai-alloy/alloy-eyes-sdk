#include "stdio.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "bsp.h"
#include "sleep.h"
#include "fpioa.h"
#include "gpio.h"
#include "syslog.h"
#include "gpiohs.h"
#include "sysctl.h"
#include "uarths.h"
#include "gpio.h"

#include "io_key.h"
#include "board_config.h"

static bool is_key_irq_come = false;
static bool is_poweon_first = true;

static const char *TAG = "IO-KEY";

static void key_mux_io()
{
	fpioa_set_function(IO_KEY_PIN_NUM, FUNC_GPIOHS0 + IO_KEY_FUNC_GPIOHS_NUM);
    gpiohs_set_drive_mode(IO_KEY_FUNC_GPIOHS_NUM, GPIO_DM_INPUT);
    gpiohs_set_pin_edge(IO_KEY_FUNC_GPIOHS_NUM, GPIO_PE_BOTH);
}

static int key_irq_cb(void *ctx)
{
	is_key_irq_come = true;
}

void key_init(void)
{
	key_mux_io();

	gpiohs_irq_register(IO_KEY_FUNC_GPIOHS_NUM,1,key_irq_cb,NULL);

	LOGI(TAG, "key_init successful!");
}

int key_detect(key_event_t *keyEvent)
{	
	gpio_pin_value_t value;
	
	if(is_poweon_first){
		LOGI(TAG, "is_poweon_first");
		is_poweon_first = false;
		return -1;
	}
	
	if(is_key_irq_come){ 
		is_key_irq_come = false;
		value = gpiohs_get_pin(IO_KEY_FUNC_GPIOHS_NUM);
		keyEvent->key_num = IO_KEY_FUNC_GPIOHS_NUM;
		keyEvent->press = value;
		LOGI(TAG, "key key_num = %d",keyEvent->key_num);
		LOGI(TAG, "key press = %d",keyEvent->press);
		return 0;
	}

	return -1;
}

