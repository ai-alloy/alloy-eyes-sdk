#ifndef _TPDRIVER_H
#define _TPDRIVER_H

#include "board_config.h"

#ifdef USE_RTP_PANEL

struct touch
{
  uint16_t x;
  uint16_t y;
  char press;
}; 

uint16_t read_ad(uint8_t cmd);
struct touch read_fiter();
void io_init_tp();
void get_rtp_data();

#endif

#endif
