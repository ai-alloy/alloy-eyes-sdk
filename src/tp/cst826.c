#include "stdio.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "bsp.h"
#include "sleep.h"
#include "fpioa.h"
#include "i2c.h"
#include "gpio.h"
#include "spi.h"
#include "syslog.h"
#include "gpiohs.h"
#include "sysctl.h"
#include "uarths.h"
#include "gpio.h"
#include "cst826.h"

#ifdef SUPPORT_CTP_CST0

#define CTP_I2C_NUM	I2C_DEVICE_2

static bool is_ctp_irq_come = false;
static const char *TAG = "CST826";

static void ctp_mux_io()
{
	//mux reset pin and set to output
	fpioa_set_function(CTP_RST_PIN_NUM, FUNC_GPIOHS0 + CTP_RST_FUNC_GPIOHS_NUM);
    gpiohs_set_drive_mode(CTP_RST_FUNC_GPIOHS_NUM, GPIO_DM_OUTPUT);

	//mux irq pin and set to pe falling
	fpioa_set_function(CTP_IRQ_PIN_NUM, FUNC_GPIOHS0 + CTP_IRQ_FUNC_GPIOHS_NUM);
    gpiohs_set_drive_mode(CTP_IRQ_FUNC_GPIOHS_NUM, GPIO_DM_INPUT);
    gpiohs_set_pin_edge(CTP_IRQ_FUNC_GPIOHS_NUM, GPIO_PE_FALLING);

	//mux i2c to num-2
	fpioa_set_function(CTP_I2C_SCLK_PIN_NUM, FUNC_I2C2_SCLK);
	fpioa_set_function(CTP_I2C_SDA_PIN_NUM, FUNC_I2C2_SDA);
}

static int cpt_irq_cb(void *ctx)
{
	is_ctp_irq_come = true;
}

static void ctp_reset_set(uint8_t val)
{
    gpiohs_set_pin(CTP_RST_FUNC_GPIOHS_NUM, val); 
}

bool ctp_hynitron_cst0_init(void)
{
 	ctp_mux_io();
#if (CTP_HYNITRON_EXT == 1)
    ctp_hynitron_update();
#endif
	 i2c_init(CTP_I2C_NUM, CTP_SLAVER_ADDR >> 1, 7, 100000);

	//reset cst826
     ctp_reset_set(0);
     msleep(10);
     ctp_reset_set(1);
	 msleep(20);

	 gpiohs_irq_register(CTP_IRQ_FUNC_GPIOHS_NUM,1,cpt_irq_cb,NULL);
	 
     LOGI(TAG, "ctp_cst0_init successful!");
	 
     return CTP_TRUE;
}

bool cpt_cst0_get_data(cpt_event_t *ctpev)
{
	uint8_t lvalue[5];
	uint16_t model = 0;
    uint8_t reg_buf;
	
	configASSERT(ctpev);
	
	if(is_ctp_irq_come){
		is_ctp_irq_come = false;

	    reg_buf = CTP_GET_DATA_REG & 0xff;
		if(0 != i2c_recv_data(CTP_I2C_NUM, &reg_buf, 1, lvalue, 5)){
			LOGE(TAG, "====ctp recv i2c data failed====");
			return CTP_FALSE;
		}
		
		model = lvalue[0];
		//LOGD(TAG, "ctp_get_data finger_num = %d", model);

		ctpev->press = (uint16_t)model;

		/*
		only support ONE fingure, not FIVE fingures;
		0 fingure means UP EVENT,1 or 2 fingure means DOWN EVENT
		*/

		if(model == 0){
			LOGI(TAG, "piont:x = %d, y = %d, press = %d(UP EVENT)", ctpev->points.x, ctpev->points.y, ctpev->press);
		}else if((model == 1) || (model == 2)){
			ctpev->points.x = (((uint16_t)(lvalue[1]&0x0f))<<8) | lvalue[2];
	   	 	ctpev->points.y = (((uint16_t)(lvalue[3]&0x0f))<<8) | lvalue[4];
			LOGI(TAG, "piont:x = %d, y = %d, press = %d(DOWN EVENT)", ctpev->points.x, ctpev->points.y, ctpev->press);
		}else{
			return CTP_FALSE;
		}
		
		return CTP_TRUE;
	}

	return CTP_FALSE;
}
#endif

