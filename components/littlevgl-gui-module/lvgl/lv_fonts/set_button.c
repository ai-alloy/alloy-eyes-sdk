#include "../../lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

const LV_ATTRIBUTE_MEM_ALIGN uint8_t set_button_map[] = {
  0x54, 0x52, 0x54, 0xff, 	/*Color of index 0*/
  0x74, 0x76, 0x74, 0xff, 	/*Color of index 1*/
  0x64, 0x62, 0x64, 0xff, 	/*Color of index 2*/
  0x84, 0x82, 0x84, 0xff, 	/*Color of index 3*/
  0x5c, 0x5a, 0x5c, 0xff, 	/*Color of index 4*/
  0x7c, 0x7e, 0x7c, 0xff, 	/*Color of index 5*/
  0x6c, 0x6a, 0x6c, 0xff, 	/*Color of index 6*/
  0x8c, 0x8a, 0x8c, 0xff, 	/*Color of index 7*/
  0x54, 0x56, 0x54, 0xff, 	/*Color of index 8*/
  0x7c, 0x7a, 0x7c, 0xff, 	/*Color of index 9*/
  0x64, 0x66, 0x64, 0xff, 	/*Color of index 10*/
  0x84, 0x86, 0x84, 0xff, 	/*Color of index 11*/
  0x5c, 0x5e, 0x5c, 0xff, 	/*Color of index 12*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 13*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 14*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 15*/

  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0xb0, 0x07, 0x77, 0x77, 0x77, 0x77, 0x00, 0xb7, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 0x00, 0x00, 0x77, 0x77, 0x77, 0x70, 0x00, 0x00, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x78, 0x00, 0x05, 0x00, 0x00, 0x37, 0x30, 0x00, 0x09, 0x00, 0x08, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x50, 0x06, 0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x77, 0x76, 0x00, 0x97, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x76, 0x00, 0x06, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x00, 0xa7, 0x77, 0x77, 0x50, 0x00, 0x00, 0x37, 0x77, 0x77, 0xa0, 0x07, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x70, 0x00, 0x77, 0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x77, 0x77, 0x70, 0x00, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x00, 0x00, 0x07, 0x77, 0x77, 0x00, 0x03, 0x77, 0x73, 0x00, 0x07, 0x77, 0x77, 0x00, 0x00, 0x07, 0x70, 
  0x77, 0x70, 0x00, 0x04, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x74, 0x00, 0x00, 0x70, 
  0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x70, 0x0c, 0x77, 0x77, 0x77, 0x74, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 0x70, 
  0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 0x70, 
  0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 0x70, 
  0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x70, 0x02, 0x77, 0x77, 0x77, 0x76, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 0x70, 
  0x77, 0x70, 0x00, 0x04, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x77, 0x07, 0x77, 0x77, 0x74, 0x00, 0x00, 0x70, 
  0x77, 0x77, 0x00, 0x00, 0x07, 0x77, 0x77, 0x00, 0x0b, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x00, 0x07, 0x70, 
  0x77, 0x77, 0x77, 0x70, 0x00, 0x77, 0x77, 0x70, 0x00, 0x00, 0x00, 0x77, 0x77, 0x77, 0x70, 0x00, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x00, 0xa7, 0x77, 0x77, 0x50, 0x00, 0x00, 0x77, 0x77, 0x77, 0xa0, 0x07, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x07, 0x77, 0x77, 0x76, 0x00, 0x06, 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x10, 0x0a, 0x77, 0x70, 0x00, 0x00, 0x00, 0x00, 0x77, 0x72, 0x00, 0x37, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x70, 0x00, 0x01, 0x00, 0x00, 0xb7, 0x30, 0x00, 0x01, 0x00, 0x08, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0xb0, 0x00, 0x00, 0x77, 0x77, 0x77, 0x70, 0x00, 0x00, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0xb0, 0x07, 0x77, 0x77, 0x77, 0x77, 0x00, 0xb7, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 
  0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x70, 
};

lv_img_dsc_t set_button = {
  .header.always_zero = 0,
  .header.w = 37,
  .header.h = 34,
  .data_size = 710,
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .data = set_button_map,
};
