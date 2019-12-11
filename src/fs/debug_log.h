#ifndef _DEBUG_LOG_H_
#define _DEBUG_LOG_H_

#include "sysctl.h"

#define DEBUG_LOG

#ifdef DEBUG_LOG
#define debug_log(fmt,...)  \
    do \
    { \
        printf("[%lu][%s](%04d): "fmt"\r\n",sysctl_get_time_us(),__func__,__LINE__,##__VA_ARGS__); \
    }while(0)
#else
#define debug_log(fmt,...)
#endif

#endif
