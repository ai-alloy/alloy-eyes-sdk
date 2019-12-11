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

#define MOTOR_CONTROL_IO1	12
#define MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM	16

#define MOTOR_CONTROL_IO2	13
#define MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM	17

#define OPEN_CLOSE_TIME	(300)
#define DEFAULT_TIME	(3000)

static const char *TAG = "MOTOR";

//#define USE_TIMER_CONTROL

#ifdef USE_TIMER_CONTROL
#define TIMER_NOR   0
#define TIMER_CHN   0

typedef enum _motor_action{
	OPEN_DOOR = 0,
	CLOSE_DOOR,
	DEFAULT_DOOR,
}motor_action_t;

static motor_action_t motor_action = DEFAULT_DOOR;
static uint8_t stop_flag = 0;
#endif

void motor_io_mux()
{	
	LOGD(TAG, "motor_io_mux");
	fpioa_set_function(MOTOR_CONTROL_IO1, FUNC_GPIOHS0 + MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM);
	fpioa_set_function(MOTOR_CONTROL_IO2, FUNC_GPIOHS0 + MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM);
    gpiohs_set_drive_mode(MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM, GPIO_DM_OUTPUT);
	gpiohs_set_drive_mode(MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM, GPIO_DM_OUTPUT);
	gpiohs_set_pin(MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
	gpiohs_set_pin(MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
}

static void close_door()
{
	LOGD(TAG, "close_door");
	gpiohs_set_pin(MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
	gpiohs_set_pin(MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM, GPIO_PV_HIGH);
	msleep(OPEN_CLOSE_TIME);
	default_door();
}

static void open_door()
{
	LOGD(TAG, "open_door");
	gpiohs_set_pin(MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM, GPIO_PV_HIGH);
	gpiohs_set_pin(MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
	msleep(OPEN_CLOSE_TIME);
	default_door();
}

void default_door()
{
	LOGD(TAG, "default_door");
	gpiohs_set_pin(MOTOR_CONTROL_IO1_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
	gpiohs_set_pin(MOTOR_CONTROL_IO2_FUNC_GPIOHS_NUM, GPIO_PV_LOW);
}

#ifdef USE_TIMER_CONTROL
int timer_callback(void *ctx)
{
#if 0
	//LOGD(TAG, "timer_callback");
	if(DEFAULT_DOOR == motor_action){
		motor_action = OPEN_DOOR;
		default_door();
		//LOGD(TAG, "next motor_action = open door");
	}else if(OPEN_DOOR == motor_action){
		motor_action = CLOSE_DOOR;
		open_door();
		//LOGD(TAG, "next motor_action = close door");
	}else if(CLOSE_DOOR == motor_action){
		motor_action = DEFAULT_DOOR;
		close_door();
		//LOGD(TAG, "next motor_action = default door");
	}
//#else
	if(DEFAULT_DOOR == motor_action){
		timer_set_interval(TIMER_NOR, TIMER_CHN, 300000000);//300ms
		timer_set_enable(TIMER_NOR, TIMER_CHN, 1);
		if(0 == stop_flag){
			LOGD(TAG, "==============");
			stop_flag = 1;
			motor_action = OPEN_DOOR;
			open_door();
		}else if(1 == stop_flag){
			LOGD(TAG, "==============");
			stop_flag = 0;
			motor_action = CLOSE_DOOR;
			close_door();
		}
	}else if(OPEN_DOOR == motor_action || CLOSE_DOOR == motor_action){
		LOGD(TAG, "==============");
		timer_set_interval(TIMER_NOR, TIMER_CHN, 5000000000);//3s
		timer_set_enable(TIMER_NOR, TIMER_CHN, 1);
		motor_action = DEFAULT_DOOR;
		default_door();
	}
#endif
    return 0;
}

static void start_timer()
{
	timer_init(TIMER_NOR);
	timer_set_interval(TIMER_NOR, TIMER_CHN, 3e9);
	timer_irq_register(TIMER_NOR, TIMER_CHN, 1, 1, timer_callback, NULL);
	timer_set_enable(TIMER_NOR, TIMER_CHN, 1);
}
#endif

void motor_control()
{
	open_door();
	msleep(DEFAULT_TIME);
	
	close_door();
	msleep(DEFAULT_TIME);
}

