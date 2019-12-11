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
#include "gc0308.h"
#include "gpiohs.h"
#include "board_config.h"

static const char *TAG = "MAIN";

#define PLL0_OUTPUT_FREQ 400000000UL
#define PLL1_OUTPUT_FREQ 300000000UL
#define PLL2_OUTPUT_FREQ 45158400UL

/*buffer for panel*/
uint32_t g_lcd_gram0[38400] __attribute__((aligned(64)));
uint32_t g_lcd_gram1[38400] __attribute__((aligned(64)));

volatile uint8_t g_dvp_finish_flag;
volatile uint8_t g_ram_mux;

static int on_irq_dvp(void *ctx)
{
    if (dvp_get_interrupt(DVP_STS_FRAME_FINISH))
    {
        /*switch gram */
        dvp_set_display_addr(g_ram_mux ? (uint32_t)g_lcd_gram0 : (uint32_t)g_lcd_gram1);
        // dvp_clear_interrupt(DVP_STS_FRAME_FINISH);
        dvp_clear_interrupt(DVP_STS_FRAME_START | DVP_STS_FRAME_FINISH);
        g_dvp_finish_flag = 1;
    }
    else
    {
        if (g_dvp_finish_flag == 0){
            dvp_start_convert();
        }
        dvp_clear_interrupt(DVP_STS_FRAME_START);
    }

    return 0;
}

static void io_mux_init(void)
{
	/*摄像头接口定义*/
    /* Init DVP IO map and function settings */
	fpioa_set_function(CMOS_PCLK_PIN_NUM, FUNC_CMOS_PCLK);
    fpioa_set_function(CMOS_XCLK_PIN_NUM, FUNC_CMOS_XCLK);
    fpioa_set_function(CMOS_HREF_PIN_NUM, FUNC_CMOS_HREF);
    fpioa_set_function(CMOS_VSYNC_PIN_NUM, FUNC_CMOS_VSYNC);

	fpioa_set_function(CMOS_RST_PIN_NUM, FUNC_GPIOHS0 + CMOS_RST_FUNC_GPIOHS_NUM);
    gpiohs_set_drive_mode(CMOS_RST_FUNC_GPIOHS_NUM, GPIO_DM_OUTPUT);
    gpiohs_set_pin(CMOS_RST_FUNC_GPIOHS_NUM, 1);	

    //显示屏接口设置
    /* Init SPI IO map and function settings */
    fpioa_set_function(LCD_RST_PIN_NUM, FUNC_GPIOHS0 + LCD_RST_FUNC_GPIOHS_NUM);
    fpioa_set_function(LCD_DCX_PIN_NUM, FUNC_GPIOHS0 + LCD_DCX_FUNC_GPIOHS_NUM);
    fpioa_set_function(LCD_CS_PIN_NUM, FUNC_SPI0_SS3);
    fpioa_set_function(LCD_WR_PIN_NUM, FUNC_SPI0_SCLK);

	//IR LIGHT
#if (IR_LED_TEST)
	fpioa_set_function(IR_LED_PIN_NUM, FUNC_GPIOHS0 + IR_LED_FUNC_GPIOHS_NUM);
	gpiohs_set_drive_mode(IR_LED_FUNC_GPIOHS_NUM, GPIO_DM_OUTPUT);
	gpiohs_set_pin(IR_LED_FUNC_GPIOHS_NUM, 1);
#endif

    sysctl_set_spi0_dvp_data(1);
}

static void io_set_power(void)
{
    /* Set dvp and spi pin to 1.8V */
    sysctl_set_power_mode(SYSCTL_POWER_BANK6, SYSCTL_POWER_V18);
    sysctl_set_power_mode(SYSCTL_POWER_BANK7, SYSCTL_POWER_V18);
}

static void system_pll_init()
{
    /* Set CPU and dvp clk */
	sysctl_pll_set_freq(SYSCTL_PLL0, PLL0_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL1, PLL1_OUTPUT_FREQ);
    sysctl_pll_set_freq(SYSCTL_PLL2, PLL2_OUTPUT_FREQ);
    sysctl_clock_enable(SYSCTL_CLOCK_AI);
}

static void dvp_config()
{
	dvp_init(8);
	dvp_set_xclk_rate(24000000);
    dvp_enable_burst();
    dvp_set_output_enable(1, 1);
    dvp_set_image_format(DVP_CFG_RGB_FORMAT);
    dvp_set_image_size(320, 240);

	/*初始化sensor*/
	gc0308_init();
	open_gc0308_1();

	dvp_set_display_addr((uint32_t)g_lcd_gram0);
    dvp_config_interrupt(DVP_CFG_START_INT_ENABLE | DVP_CFG_FINISH_INT_ENABLE, 0);
    dvp_disable_auto();

    /*dvp interrupt config */
    plic_set_priority(IRQN_DVP_INTERRUPT, 1);
    plic_irq_register(IRQN_DVP_INTERRUPT, on_irq_dvp, NULL);
    plic_irq_enable(IRQN_DVP_INTERRUPT);
}

static void dvp_int_init()
{
    dvp_clear_interrupt(DVP_STS_FRAME_START | DVP_STS_FRAME_FINISH);
    dvp_config_interrupt(DVP_CFG_START_INT_ENABLE | DVP_CFG_FINISH_INT_ENABLE, 1);
}


/*ENTRY*/
int main(void)
{
	/*初始化系统时钟*/
	system_pll_init();
	
	/*初始化调试串口*/
    uarths_init();

	/*IO引脚复用设置*/
    io_mux_init();
	
	/*电源阈设置*/
    io_set_power();
	
	/*初始化系统中断*/
    plic_init();


    /*初始化LCD屏*/
	lcd_init();
	/*设置屏显方向*/
	lcd_set_direction_ex(DIR_YX_LRUD);
	/*初始化屏为黑色背景*/
    lcd_clear(RED);
	lcd_draw_string(115, 70, "Alloy-Eyes!", BLUE);
		
	/*初始化dvp摄像头接口*/
	dvp_config();
    /*使能系统中断请求*/
    sysctl_enable_irq();	
	/*初始化dvp相关中断*/
	dvp_int_init();

	/*初始化全局变量*/
    g_ram_mux = 0;
    g_dvp_finish_flag = 0;
	
	LOGI(TAG,"system start...");

	while (1)
    {		
    	/*等待一帧采集完成*/
		while (g_dvp_finish_flag == 0);
    	g_ram_mux ^= 0x01;
		/*显示一帧图像在屏上*/
		lcd_draw_picture(0, 0, 320, 240, g_ram_mux ? g_lcd_gram0 : g_lcd_gram1);
		/*清除标记位*/
        g_dvp_finish_flag = 0;        	
	}

    return 0;
}

