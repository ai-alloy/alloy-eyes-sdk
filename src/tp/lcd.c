/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string.h>
#include <unistd.h>
#include "lcd.h"
#include "st7789.h"
#include "font.h"
// #include "lvgl/lvgl.h"
#include <stdio.h>
// #include "board_config.h"
#include "board_config.h"
#include "sleep.h"

lcd_ctl_t lcd_ctl;

static const char *TAG = "LCD";

void lcd_polling_enable(void)
{
    lcd_ctl.mode = 0;
}

void lcd_interrupt_enable(void)
{
    lcd_ctl.mode = 1;
}

#ifdef USE_CAP_PANEL
void WriteComm(uint8_t cmd)
{
	tft_write_command(cmd);
}

void WriteData(uint8_t data)
{
    tft_write_byte(&data, 1);
}

void lcd_init_ex(void)
{
	uint8_t data2[2] = {0};
	uint8_t data5[5] = {0};
	uint8_t data14[14] = {0};

	tft_hard_init();

	WriteComm(0x01); //soft reset

	WriteComm(0x11); //Exit Sleep
	usleep(200*1000);
	
	//-----------Display and color format setting-------------//
	WriteComm(0x36); // Memory Access Control
	WriteData(0x00); // r/w scanning direction of frame memory.

	WriteComm(0x3a);//DPI=101  16bit RGB
	WriteData(0x05);//0x55 16bit 65K
	//WriteData(0x55);//0x55  

	//-------------ST7789V Frame rate setting-----------//
	WriteComm(0xb2); //Porch Setting
	data5[0] = 0x0C;
	data5[1] = 0x0C;
	data5[2] = 0x00;
	data5[3] = 0X33;
	data5[4] = 0X33;
	tft_write_byte(data5, 5);

	WriteComm(0xb7); // Gate Control
	WriteData(0x35);//0x71 ===
	
	//--------------ST7789V Power setting---------------//
	WriteComm(0xBB); //VCOMS Setting
	WriteData(0x25);

	WriteComm(0xC0); //Power control
	WriteData(0x2c); 

	WriteComm(0xC2); 
	WriteData(0X01);

	WriteComm(0xC3); 
	WriteData(0X01);//0x14 ===

	WriteComm(0xC4); 
	WriteData(0X20);

	WriteComm(0xC6); 
	WriteData(0X0F);//0x0F

	WriteComm(0xd0); //Power control
	data2[0] = 0xa4;
	data2[1] = 0xa4;
	tft_write_byte(data2, 2);

	//---------------ST7789V gamma setting-------------//
	WriteComm(0xE0); //Set Gamma Positive Voltage Gamma Control
	data14[0] = 0xd0;
	data14[1] = 0x08;
	data14[2] = 0x0e;
	data14[3] = 0x0a;
	data14[4] = 0x0a;
	data14[5] = 0x06;
	data14[6] = 0x38;
	data14[7] = 0x44;
	data14[8] = 0x50;
	data14[9] = 0x29;
	data14[10] = 0x15;
	data14[11] = 0x16;
	data14[12] = 0x33;
	data14[13] = 0x36;
	tft_write_byte(data14, 14);
	 
	WriteComm(0xE1); //Set Gamma Negative Voltage Gamma Control
	data14[0] = 0xd0;
	data14[1] = 0x07;
	data14[2] = 0x0d;
	data14[3] = 0x09;
	data14[4] = 0x08;
	data14[5] = 0x06;
	data14[6] = 0x33;
	data14[7] = 0x33;
	data14[8] = 0x4d;
	data14[9] = 0x28;
	data14[10] = 0x16;
	data14[11] = 0x15;
	data14[12] = 0x33;
	data14[13] = 0x35;
	tft_write_byte(data14, 14); 
//---------------ST7789V gamma setting end-------------//
 
	WriteComm(0x21); //Display Inversion On

	WriteComm(0xB0);//RAM Control
	data2[0] = 0x00;
	data2[1] = 0xd0;
	tft_write_byte(data2, 2);

	//TE ON
#ifdef LCD_TE_FMARK
	WriteComm(0x35);
	WriteData(0x00);
#endif

	WriteComm(0x29); //Display on		
}
#endif

void lcd_init(void)
{
    uint8_t data = 0;

    tft_hard_init();
    /*soft reset*/
    tft_write_command(SOFTWARE_RESET);
    usleep(100000);
    /*exit sleep*/
    tft_write_command(SLEEP_OFF);
    usleep(100000);
    /*pixel format*/
    tft_write_command(PIXEL_FORMAT_SET);
    data = 0x55;
    tft_write_byte(&data, 1);
    lcd_set_direction(DIR_XY_RLUD);
    /*display on*/
    tft_write_command(DISPALY_ON);

    lcd_polling_enable();
}

void lcd_set_direction(lcd_dir_t dir)
{
// #if BOARD_LICHEEDAN
// #else
//     dir |= 0x08;
// #endif
    lcd_ctl.dir = dir;
    if (dir & DIR_XY_MASK)
    {
        lcd_ctl.width = LCD_Y_MAX - 1;
        lcd_ctl.height = LCD_X_MAX - 1;
    }
    else
    {
        lcd_ctl.width = LCD_X_MAX - 1;
        lcd_ctl.height = LCD_Y_MAX - 1;
    }

    tft_write_command(MEMORY_ACCESS_CTL);
    tft_write_byte((uint8_t *)&dir, 1);
}

void lcd_set_direction_ex(lcd_dir_t dir)
{
	for(int i = 0; i < 3; i++){ 
		lcd_set_direction(dir);
	    msleep(10);
	}
}

/*设置区域*/
void lcd_set_area(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    uint8_t data[4] = {0};

    data[0] = (uint8_t)(x1 >> 8);
    data[1] = (uint8_t)(x1);
    data[2] = (uint8_t)(x2 >> 8);
    data[3] = (uint8_t)(x2);
    tft_write_command(HORIZONTAL_ADDRESS_SET);
    tft_write_byte(data, 4);

    data[0] = (uint8_t)(y1 >> 8);
    data[1] = (uint8_t)(y1);
    data[2] = (uint8_t)(y2 >> 8);
    data[3] = (uint8_t)(y2);
    tft_write_command(VERTICAL_ADDRESS_SET);
    tft_write_byte(data, 4);

    tft_write_command(MEMORY_WRITE);
}

/*画点*/
void lcd_draw_point(uint16_t x, uint16_t y, uint16_t color)
{
    
    // tft_write_half(&color, 1);

    uint32_t data = ((uint32_t)color << 16) | (uint32_t)color;

    lcd_set_area(x, y, x, y);
	//tft_fill_data(&data, 1);
    tft_fill_data(&data, 2);
}

/*写一个字符*/
void lcd_draw_char(uint16_t x, uint16_t y, char c, uint16_t color)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t data = 0;

    for (i = 0; i < 16; i++)
    {
        data = ascii0816[c * 16 + i];
        for (j = 0; j < 8; j++)
        {
            if (data & 0x80)
                lcd_draw_point(x + j, y, color);
            data <<= 1;
        }
        y++;
    }
}

/*写字符串*/
void lcd_draw_string(uint16_t x, uint16_t y, char *str, uint16_t color)
{
    while (*str)
    {
        lcd_draw_char(x, y, *str, color);
        str++;
        x += 8;
    }
}

/*写字符串*/
void lcd_ram_draw_string(char *str, uint32_t *ptr, uint16_t font_color, uint16_t bg_color)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t data = 0;
    uint8_t *pdata = NULL;
    uint16_t width = 0;
    uint32_t *pixel = NULL;

    width = 4 * strlen(str);
    while (*str)
    {
        pdata = (uint8_t *)&ascii0816[(*str) * 16];
        for (i = 0; i < 16; i++)
        {
            data = *pdata++;
            pixel = ptr + i * width;
            for (j = 0; j < 4; j++)
            {
                switch (data >> 6)
                {
                    case 0:
                        *pixel = ((uint32_t)bg_color << 16) | bg_color;
                        break;
                    case 1:
                        *pixel = ((uint32_t)bg_color << 16) | font_color;
                        break;
                    case 2:
                        *pixel = ((uint32_t)font_color << 16) | bg_color;
                        break;
                    case 3:
                        *pixel = ((uint32_t)font_color << 16) | font_color;
                        break;
                    default:
                        *pixel = 0;
                        break;
                }
                data <<= 2;
                pixel++;
            }
        }
        str++;
        ptr += 4;
    }
}

/*清屏*/
void lcd_clear(uint16_t color)
{
    uint32_t data = ((uint32_t)color << 16) | (uint32_t)color;

    lcd_set_area(0, 0, lcd_ctl.width, lcd_ctl.height);
    tft_fill_data(&data, LCD_X_MAX * LCD_Y_MAX / 2);
}

/*画长方形*/
void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t width, uint16_t color)
{
	uint32_t data_buf[640] = {0};
	uint32_t *p = data_buf;
	uint32_t data = color;
	uint32_t index = 0;
	
	data = (data << 16) | data;
	for (index = 0; index < 160 * width; index++)
		*p++ = data;

	lcd_set_area(x1, y1, x2, y1 + width - 1);
	tft_write_word(data_buf, ((x2 - x1 + 1) * width + 1) / 2, 0);
	lcd_set_area(x1, y2 - width + 1, x2, y2);
	tft_write_word(data_buf, ((x2 - x1 + 1) * width + 1) / 2, 0);
	lcd_set_area(x1, y1, x1 + width - 1, y2);
	tft_write_word(data_buf, ((y2 - y1 + 1) * width + 1) / 2, 0);
	lcd_set_area(x2 - width + 1, y1, x2, y2);
	tft_write_word(data_buf, ((y2 - y1 + 1) * width + 1) / 2, 0);
}

/*填充指定区域*/
void lcd_draw_picture(uint16_t x1, uint16_t y1, uint16_t width, uint16_t height, uint32_t *ptr)
{
    lcd_set_area(x1, y1, x1 + width - 1, y1 + height - 1);
    tft_write_word(ptr, width * height / 2, lcd_ctl.mode ? 2 : 0);
}
/*填充指定区域*/
void lcd_draw_picture_half(uint16_t x1, uint16_t y1, uint16_t width, uint16_t height, uint16_t *ptr)
{
    lcd_set_area(x1, y1, x1 + width - 1, y1 + height - 1);
    tft_write_half(ptr, width * height);
}

//画线
//x1,y1:起点坐标
//x2,y2:终点坐标  
void lcd_drawline(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向
	else if(delta_x==0)incx=0;//垂直线
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		lcd_draw_point(uRow,uCol,color);//画点
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}

//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void lcd_draw_circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下一个点位置的标值
	while(a<=b)
	{
		lcd_draw_point(x0+a,y0-b,color);             //5
 		lcd_draw_point(x0+b,y0-a,color);             //0           
		lcd_draw_point(x0+b,y0+a,color);             //4               
		lcd_draw_point(x0+a,y0+b,color);             //6 
		lcd_draw_point(x0-a,y0+b,color);             //1       
 		lcd_draw_point(x0-b,y0+a,color);             
		lcd_draw_point(x0-a,y0-b,color);             //2             
  		lcd_draw_point(x0-b,y0-a,color);             //7     	         
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
}



// /****************************lv_gui interface******************************/
// void lv_lcd_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
// {
// 	if(x2 < 0 || y2 < 0 || x1 > lcd_ctl.width - 1 || y1 > lcd_ctl.height - 1){
// 		printf("over the screen!\n");
//         lv_flush_ready();
//         return;
//     }
// 	uint16_t height,width;
// 	width=x2-x1+1; 			//得到填充宽度
// 	height=y2-y1+1;			//得到填充高度
//     // printf("lv_lcd_flush:x1:%d,y1:%d,x2:%d,y2:%d,width:%d,height:%d\n",x1,y1,x2,y2,width,height);
// 	lcd_draw_picture_half(x1,y1,width,height,color_p);
// 	lv_flush_ready();
// }

// void lv_lcd_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color)
// {
	
// 	if(x2 < 0 || y2 < 0 || x1 > lcd_ctl.width - 1 || y1 > lcd_ctl.height - 1){
// 		printf("over the screen!\n");
//         // lv_flush_ready();
//         return;
//     }
// 	/*Truncate the area to the screen*/
//     int32_t act_x1 = x1 < 0 ? 0 : x1;
//     int32_t act_y1 = y1 < 0 ? 0 : y1;
//     int32_t act_x2 = x2 > lcd_ctl.width - 1 ? lcd_ctl.width - 1 : x2;
//     int32_t act_y2 = y2 > lcd_ctl.height - 1 ? lcd_ctl.height - 1 : y2;

// 	uint16_t height,width;
// 	width=act_x2-act_x1; 			//得到填充宽度
// 	height=act_y2-act_y1;			//得到填充高度
//     printf("lv_lcd_fill:x1:%d,act_x1:%d,y1:%d,act_y1:%d,x2:%d,y2:%d,width:%d,height:%d\n",x1,act_x1,y1,act_y1,x2,y2,width,height);

//     uint32_t data = ((uint32_t)color.full << 16) | (uint32_t)color.full;
//     lcd_set_area(act_x1, act_y1, act_x2-1 , act_y2-1);
//     tft_fill_data(&data, width * height / 2);
	
// }

// void lv_lcd_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
// {
// 	if(x2 < 0 || y2 < 0 || x1 > lcd_ctl.width - 1 || y1 > lcd_ctl.height - 1){
// 		printf("over the screen!\n");
//         // lv_flush_ready();
//         return;
//     }
// 	/*Truncate the area to the screen*/
//     int32_t act_x1 = x1 < 0 ? 0 : x1;
//     int32_t act_y1 = y1 < 0 ? 0 : y1;
//     int32_t act_x2 = x2 > lcd_ctl.width - 1 ? lcd_ctl.width - 1 : x2;
//     int32_t act_y2 = y2 > lcd_ctl.height - 1 ? lcd_ctl.height - 1 : y2;

// 	uint16_t height,width;
// 	width=act_x2-act_x1+1; 			//得到填充宽度
// 	height=act_y2-act_y1+1;			//得到填充高度
    
//     // printf("lv_lcd_map:x1:%d,y1:%d,x2:%d,y2:%d,width:%d,height:%d\n",x1,y1,x2,y2,width,height);

//     lcd_draw_picture_half(act_x1,act_y1,width,height,color_p);

// }

