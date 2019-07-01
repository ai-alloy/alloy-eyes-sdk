#include <stdio.h>
#include "bsp.h"
#include "sleep.h"
#include "fpioa.h"
#include "gpio.h"
#include "spi.h"
#include "gpiohs.h"
#include "sysctl.h"
#include "uarths.h"
#include "syslog.h"
#include "gpio.h"
#include "tp_driver.h"

#ifdef USE_RTP_PANEL

static const char *TAG = "RTP";

#define clk_0  gpiohs_set_pin(RTP_SCLK_FUNC_GPIOHS_NUM,GPIO_PV_LOW)
#define clk_1  gpiohs_set_pin(RTP_SCLK_FUNC_GPIOHS_NUM,GPIO_PV_HIGH)

#define mosi_0 gpiohs_set_pin(RTP_MOSI_FUNC_GPIOHS_NUM,GPIO_PV_LOW)
#define mosi_1 gpiohs_set_pin(RTP_MOSI_FUNC_GPIOHS_NUM,GPIO_PV_HIGH)

#define ERR_RANGE 5 //误差范围 

void io_init_tp()
{
   fpioa_set_function(RTP_SCLK_PIN_NUM,FUNC_GPIOHS0 + RTP_SCLK_FUNC_GPIOHS_NUM);
   fpioa_set_function(RTP_MOSI_PIN_NUM,FUNC_GPIOHS0 + RTP_MOSI_FUNC_GPIOHS_NUM);
   fpioa_set_function(RTP_MISO_PIN_NUM,FUNC_GPIOHS0 + RTP_MISO_FUNC_GPIOHS_NUM);
   
   gpiohs_set_drive_mode(RTP_SCLK_FUNC_GPIOHS_NUM,GPIO_DM_OUTPUT);
   gpiohs_set_drive_mode(RTP_MOSI_FUNC_GPIOHS_NUM,GPIO_DM_OUTPUT);
   gpiohs_set_drive_mode(RTP_MISO_FUNC_GPIOHS_NUM,GPIO_DM_INPUT_PULL_UP);

   fpioa_set_function(RTP_PEN_PIN_NUM, FUNC_GPIOHS0 + RTP_PEN_FUNC_GPIOHS_NUM);
   gpiohs_set_drive_mode(RTP_PEN_FUNC_GPIOHS_NUM,GPIO_DM_INPUT_PULL_DOWN);
}

void spi_write(uint8_t dat)
{
  int i; 
  
	clk_0; 
	for(i=0;i<8;i++)
	{ 
		if(dat&0x80)
		  mosi_1;
		else
		  mosi_0;
		dat <<= 1; 
		clk_0;
		clk_1;
	}
}

uint16_t spi_read()
{
	int i;
	uint16_t dat = 0;
	clk_0;
	for(i=0;i<12;i++)
	{ 
		if(gpiohs_get_pin(RTP_MISO_FUNC_GPIOHS_NUM) == GPIO_PV_HIGH)
			dat |= 1;
		clk_1; 
		clk_0; 
		dat <<= 1;
	}

	return dat;
}

uint16_t read_ad(uint8_t cmd)
{
  int i;
  clk_0;
 
  spi_write(cmd);
  usleep(100);
  clk_1;
  usleep(100);
  clk_0;
  usleep(100);
  return spi_read();
}

struct touch read_fiter()
{
   volatile struct touch touch1; 
   static uint16_t last_xx = 0;
   static uint16_t last_yy = 0;
   uint16_t x1;
   uint16_t x2;
   uint16_t y1;
   uint16_t y2;

   //touch1.x =0;
   //touch1.y =0;
   //touch1.press =0;
   x1 = read_ad(0xd0);
   //usleep(200); 
   y1 = read_ad(0x90);
   //usleep(200);
   x2 = read_ad(0xd0);
   //usleep(200);
   y2 = read_ad(0x90);

	if(((x2 <= x1 && x1 < x2 + ERR_RANGE) || (x1 <= x2 && x2 < x1 + ERR_RANGE) &&
		((y2 <= y1 && y1 < y2 + ERR_RANGE) || (y1 <= y2 && y2 < y1 + ERR_RANGE))))
   {
       touch1.x=-0.06793*((x1+x2)/2)+258.4;
       touch1.y=-0.09142*((y1+y2)/2)+354.7;   
       if(touch1.x>=240)
             touch1.x = 239;
       if( touch1.y >= 320)
             touch1.y = 319;  
       touch1.x=240-(-0.06793*((x1+x2)/2)+258.4);
       touch1.y=320-(-0.09142*((y1+y2)/2)+354.7);     
       
   }
 
	if(touch1.x == 0 && touch1.y == 0)
	{
		touch1.x = last_xx;
		touch1.y = last_yy;
		touch1.press = 0;
		
		return touch1; 
	}
	else
	{
		last_xx = touch1.x;
		last_yy = touch1.y;
	}
	
    touch1.press = 1; 
    return touch1;   
}

void get_rtp_data()
{
	struct touch tp_point;

    tp_point.x = 0;
    tp_point.y = 0;
    tp_point.press = 0;
  
    if(gpiohs_get_pin(RTP_PEN_FUNC_GPIOHS_NUM) == GPIO_PV_LOW)
    {
     	msleep(1);
     	if(gpiohs_get_pin(RTP_PEN_FUNC_GPIOHS_NUM) == GPIO_PV_LOW)
     	{
       		tp_point.x = 0;
 			tp_point.y = 0;
 			tp_point.press = 0;
 			tp_point = read_fiter();
        	if(tp_point.x >= 240)
            	tp_point.x = 239;
       		if(tp_point.y >= 319)
                tp_point.y = 319;
			LOGI(TAG, "rtp data point.x = %d",tp_point.x);
			LOGI(TAG, "rtp data point.y = %d",tp_point.y);
			LOGI(TAG, "rtp data point.press = %d",tp_point.press);
		}
	}
}
#endif
