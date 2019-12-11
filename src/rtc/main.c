#include <stdio.h>
#include "rtc.h"
#include <unistd.h>
#include "syslog.h"

static const char *TAG = "RTC";

void get_date_time(void)
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    rtc_timer_get(&year, &month, &day, &hour, &minute, &second);
    LOGD(TAG, "%4d-%d-%d %d:%d:%d", year, month, day, hour, minute, second);
}

int main(void)
{
	int year = 2019;
    int month = 6;
    int day = 24;
    int hour = 20;
    int minute = 13;
    int second = 29;
	
    rtc_init();
	LOGD(TAG, "set rtc time:%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
    rtc_timer_set(year, month, day, hour, minute, second);
    while(1)
    {
        sleep(1);
        get_date_time();
    }
    return 0;
}
