#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

/****************BOARD SELECT****************/
//#define BOARD_VERSION_V1D0
#define BOARD_VERSION_V1D1
#if ((defined BOARD_VERSION_V1D0) && (defined BOARD_VERSION_V1D1)) || ((!defined BOARD_VERSION_V1D0) && (!defined BOARD_VERSION_V1D1))
#error must select only one type board
#endif

/****************MACRO DEFINE****************/
/* panel select */
#define USE_RTP_PANEL
//#define USE_CAP_PANEL
#if ((defined USE_CAP_PANEL) && (defined USE_RTP_PANEL)) || ((!defined USE_CAP_PANEL) && (!defined USE_RTP_PANEL))
#error panel only select one
#endif
#ifdef USE_CAP_PANEL
//#define LCD_TE_FMARK
#define SUPPORT_CTP_CST0	
#endif

#define IR_LED_TEST		(0)

/***************** IO MUX ********************/
#ifdef BOARD_VERSION_V1D0
/* lcd panel */
#define LCD_CS_PIN_NUM			39 //IO39

#define LCD_RST_PIN_NUM			38 //IO38
#define LCD_RST_FUNC_GPIOHS_NUM	2  				//GPIOHS2

#define LCD_DCX_PIN_NUM			37 //IO37
#define LCD_DCX_FUNC_GPIOHS_NUM	3  				//GPIOHS3

#define LCD_WR_PIN_NUM			36 //IO36

#ifdef LCD_TE_FMARK
#define LCD_FMARK_PIN_NUM		17 //IO17
#define LCD_FMARK_FUNC_GPIOHS_NUM	4			//GPIOHS4
#endif

/* cmos sensor dvp */
#define CMOS_PCLK_PIN_NUM		21 //IO21
#define CMOS_XCLK_PIN_NUM		20 //IO20
#define CMOS_HREF_PIN_NUM		19 //IO19
#define CMOS_VSYNC_PIN_NUM		18 //IO18

#define CMOS_RST_PIN_NUM		25 //IO25
#define CMOS_RST_FUNC_GPIOHS_NUM	5  			//GPIOHS5

#define CMOS_I2C_SCLK_PIN_NUM	24 //IO24
#define CMOS_I2C_SDA1_PIN_NUM	23 //IO23
#define CMOS_I2C_SDA2_PIN_NUM	22 //IO22

/* r-g-b led */
#define LED_R_PIN_NUM			45 //IO45
#define LED_R_FUNC_GPIOHS_NUM	6  				//GPIOHS6

#define LED_G_PIN_NUM			47 //IO47
#define LED_G_FUNC_GPIOHS_NUM	7  				//GPIOHS7

#define LED_B_PIN_NUM			46 //IO46
#define LED_B_FUNC_GPIOHS_NUM	8  				//GPIOHS8

/* ir light control */
#define IR_LED_PIN_NUM			7  //IO07
#define IR_LED_FUNC_GPIOHS_NUM	9 				//GPIOHS9

/* ctp */
#ifdef SUPPORT_CTP_CST0
#define CTP_RST_PIN_NUM			8 //IO08
#define CTP_RST_FUNC_GPIOHS_NUM	10 				//GPIOHS10

#define CTP_IRQ_PIN_NUM			11 //IO11
#define CTP_IRQ_FUNC_GPIOHS_NUM	11 				//GPIOHS11

#define CTP_I2C_SCLK_PIN_NUM	10 //IO10
#define CTP_I2C_SDA_PIN_NUM		9  //IO9
#endif

#ifdef USE_RTP_PANEL/*rtp*/
#define RTP_SCLK_PIN_NUM		9  //IO9
#define RTP_SCLK_FUNC_GPIOHS_NUM	10 			//GPIOHS10

#define RTP_MOSI_PIN_NUM		10 //IO10
#define RTP_MOSI_FUNC_GPIOHS_NUM	11 			//GPIOHS11

#define RTP_MISO_PIN_NUM		8  //IO08
#define RTP_MISO_FUNC_GPIOHS_NUM	12 			//GPIOHS12

#define RTP_PEN_PIN_NUM			11 //IO11
#define RTP_PEN_FUNC_GPIOHS_NUM		13 			//GPIOHS13
#endif

/* tf/sd spi */
#define SD_SPI_SCLK_PIN_NUM		27  //IO27
#define SD_SPI_MOSI_PIN_NUM		28  //IO28
#define SD_SPI_MISO_PIN_NUM		26  //IO26
#define SD_SPI_CS_PIN_NUM		29  //IO29
#define SD_SPI_CS_FUNC_GPIOHS_NUM	14 			//GPIOHS14

/* speaker(i2s)*/
#define SPK_I2S_OUT_D1_PIN_NUM		33  //IO33
#define SPK_I2S_SCLK_PIN_NUM		35  //IO35
#define SPK_I2S_WS_PIN_NUM			34  //IO34

/* mic(i2s)*/
#define MIC_I2S_IN_D0_PIN_NUM		31  //IO31
#define MIC_I2S_SCLK_PIN_NUM		32  //IO32
#define MIC_I2S_WS_PIN_NUM			30  //IO30

/* io-key */
#define IO_KEY_PIN_NUM				44 //IO44
#define IO_KEY_FUNC_GPIOHS_NUM		15 			//GPIOHS15

/* jtag */
#define JTAG_TCK_PIN_NUM		0  //IO0
#define JTAG_TDI_PIN_NUM		1  //IO1
#define JTAG_TMS_PIN_NUM		2  //IO2
#define JTAG_TDO_PIN_NUM		3  //IO3

/* eth */
#define ETH_CSSN_PIN_NUM		17  //IO17
#define ETH_INT_PIN_NUM			15  //IO15
#define ETH_RST_PIN_NUM			14  //IO14
#define ETH_SCLK_PIN_NUM		13  //IO13
#define ETH_MISO_PIN_NUM		12  //IO12
#define ETH_MOSI_PIN_NUM		6   //IO06
#else def(BOARD_VERSION_V1D1)
/* lcd panel */
#define LCD_CS_PIN_NUM			39 //IO39

#define LCD_RST_PIN_NUM			38 //IO38
#define LCD_RST_FUNC_GPIOHS_NUM	2  				//GPIOHS2

#define LCD_DCX_PIN_NUM			37 //IO37
#define LCD_DCX_FUNC_GPIOHS_NUM	3  				//GPIOHS3

#define LCD_WR_PIN_NUM			36 //IO36
#define LCD_RD_PIN_NUM			41 //IO41

#ifdef LCD_TE_FMARK
#define LCD_FMARK_PIN_NUM		40 //IO40
#define LCD_FMARK_FUNC_GPIOHS_NUM	4			//GPIOHS4
#endif

/* cmos sensor dvp */
#define CMOS_PCLK_PIN_NUM		21 //IO21
#define CMOS_XCLK_PIN_NUM		20 //IO20
#define CMOS_HREF_PIN_NUM		19 //IO19
#define CMOS_VSYNC_PIN_NUM		18 //IO18

#define CMOS_RST_PIN_NUM		25 //IO25
#define CMOS_RST_FUNC_GPIOHS_NUM	5  			//GPIOHS5

#define CMOS_I2C_SCLK_PIN_NUM	24 //IO24
#define CMOS_I2C_SDA1_PIN_NUM	23 //IO23
#define CMOS_I2C_SDA2_PIN_NUM	22 //IO22

/* r-g-b led */
#define LED_R_PIN_NUM			45 //IO45
#define LED_R_FUNC_GPIOHS_NUM	6  				//GPIOHS6

#define LED_G_PIN_NUM			47 //IO47
#define LED_G_FUNC_GPIOHS_NUM	7  				//GPIOHS7

#define LED_B_PIN_NUM			46 //IO46
#define LED_B_FUNC_GPIOHS_NUM	8  				//GPIOHS8

/* ir light control */
#define IR_LED_PIN_NUM			17 //IO17
#define IR_LED_FUNC_GPIOHS_NUM	9 				//GPIOHS9

/* ctp */
#ifdef SUPPORT_CTP_CST0
#define CTP_RST_PIN_NUM			12 //IO12
#define CTP_RST_FUNC_GPIOHS_NUM	10 				//GPIOHS10

#define CTP_IRQ_PIN_NUM			15 //IO15
#define CTP_IRQ_FUNC_GPIOHS_NUM	11 				//GPIOHS11

#define CTP_I2C_SCLK_PIN_NUM	14 //IO14
#define CTP_I2C_SDA_PIN_NUM		13  //IO13
#endif

#ifdef USE_RTP_PANEL/*rtp*/
#define RTP_SCLK_PIN_NUM		13  //IO13
#define RTP_SCLK_FUNC_GPIOHS_NUM	10 			//GPIOHS10

#define RTP_MOSI_PIN_NUM		14 //IO14
#define RTP_MOSI_FUNC_GPIOHS_NUM	11 			//GPIOHS11

#define RTP_MISO_PIN_NUM		12  //IO12
#define RTP_MISO_FUNC_GPIOHS_NUM	12 			//GPIOHS12

#define RTP_PEN_PIN_NUM			15 //IO15
#define RTP_PEN_FUNC_GPIOHS_NUM		13 			//GPIOHS13
#endif

/* tf/sd spi */
#define SD_SPI_SCLK_PIN_NUM		27  //IO27
#define SD_SPI_MOSI_PIN_NUM		28  //IO28
#define SD_SPI_MISO_PIN_NUM		26  //IO26
#define SD_SPI_CS_PIN_NUM		29  //IO29
#define SD_SPI_CS_FUNC_GPIOHS_NUM	14 			//GPIOHS14

/* speaker(i2s)*/
#define SPK_I2S_OUT_D1_PIN_NUM		33  //IO33
#define SPK_I2S_SCLK_PIN_NUM		35  //IO35
#define SPK_I2S_WS_PIN_NUM			34  //IO34

/* mic(i2s)*/
#define MIC_I2S_IN_D0_PIN_NUM		32  //IO32
#define MIC_I2S_SCLK_PIN_NUM		31  //IO31
#define MIC_I2S_WS_PIN_NUM			30  //IO30

/* io-key */
#define IO_KEY_PIN_NUM				44 //IO44
#define IO_KEY_FUNC_GPIOHS_NUM		15 			//GPIOHS15

/* jtag */
#define JTAG_TCK_PIN_NUM		0  //IO0
#define JTAG_TDI_PIN_NUM		1  //IO1
#define JTAG_TMS_PIN_NUM		2  //IO2
#define JTAG_TDO_PIN_NUM		3  //IO3

/* eth */
#define ETH_CSSN_PIN_NUM		12  //IO12
#define ETH_INT_PIN_NUM			10  //IO10
#define ETH_RST_PIN_NUM			9   //IO9
#define ETH_SCLK_PIN_NUM		8   //IO8
#define ETH_MISO_PIN_NUM		7   //IO7
#define ETH_MOSI_PIN_NUM		6   //IO06
#endif

#endif /* _BOARD_CONFIG_H_ */
