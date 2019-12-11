#ifndef _CST826_H_
#define _CST826_H_

#include "board_config.h"

#ifdef SUPPORT_CTP_CST0

#define CTP_TRUE    1
#define CTP_FALSE   0

#define CTP_SLAVER_ADDR		0x2A
#define CTP_HYNITRON_EXT    0 // enable update

//ctp reg
#define CTP_GET_DATA_REG 		0x02

typedef struct _ctp_points{
	uint16_t x;
	uint16_t y;
}ctp_points_t;

typedef struct _ctp_event{
	ctp_points_t points;	
	bool press;
}cpt_event_t;

bool ctp_hynitron_cst0_init(void);
bool cpt_cst0_get_data(cpt_event_t *ctpev);

#endif

#endif
