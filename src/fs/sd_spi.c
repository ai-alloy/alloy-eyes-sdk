#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "fpioa.h"
#include "utils.h"
#include "math.h"
#include "syslog.h"
#include "gpiohs.h"
#include "gpio.h"

#include "sdcard.h"
#include "ff.h"

#include "board_config.h"

static bool sd_init_flag = false;
static const char *TAG = "SD-SPI";

static int sdcard_spi_init(void)
{
    static FATFS sdcard_fs;
    FRESULT status;
    DIR dj;
    FILINFO fno;

    status = f_mount(&sdcard_fs, _T("0:"), 1);
    LOGI(TAG,"mount sdcard:%d", status);
    if (status != FR_OK)
        return status;

    LOGI(TAG,"printf filename");
    status = f_findfirst(&dj, &fno, _T("0:"), _T("*"));
    while (status == FR_OK && fno.fname[0]) {
        if (fno.fattrib & AM_DIR)
            LOGI(TAG,"dir:%s", fno.fname);
        else
            LOGI(TAG,"file:%s", fno.fname);
        status = f_findnext(&dj, &fno);
    }
    f_closedir(&dj);
    return 0;
}

/*配置SD card硬件*/
static void sd_spi_io_config()
{
	/*sd card io27,28,26,29*/
	fpioa_set_function(SD_SPI_SCLK_PIN_NUM, FUNC_SPI1_SCLK);
	fpioa_set_function(SD_SPI_MOSI_PIN_NUM, FUNC_SPI1_D0);
	fpioa_set_function(SD_SPI_MISO_PIN_NUM, FUNC_SPI1_D1);
	fpioa_set_function(SD_SPI_CS_PIN_NUM, FUNC_GPIOHS0 + SD_SPI_CS_FUNC_GPIOHS_NUM);
	set_sd_cs_num(SD_SPI_CS_FUNC_GPIOHS_NUM);
}

/*
 * @brief  初始化sd card信息.
 * @param  None
 * @retval :
 *         - 0xFF: 初始化失败
 *         - 0: 初始化成功，可由cardinfo获取SD card信息
 */

int sdcard_init(void)
{
    uint8_t status;

	sd_spi_io_config();
	
    status = sd_init();
    LOGI(TAG,"sd init %d", status);
    if (status != 0){
		LOGE(TAG,"card init failed");
        return status;
    }

    LOGI(TAG,"card init successful");
    LOGI(TAG,"CardCapacity:%ld(%dMB)", cardinfo.CardCapacity,(int)(cardinfo.CardCapacity/1024/1024));
    LOGI(TAG,"CardBlockSize:%d", cardinfo.CardBlockSize);

    if(sdcard_spi_init()){
       LOGE(TAG,"sdcard FAT32 failed");
	   return 0xFF;
    }
	
	sd_init_flag = true;
	
	LOGI(TAG,"sdcard FAT32 ok");
	
    return 0;
}

void sdcard_test()
{
	FRESULT ret = FR_OK;
	FIL file_s;
	uint32_t ret_len = 0;

	const char *path = "0:test1.txt";
	char *test_data = "123321";
	char read_buf[512] = {0};
	
	if(!sd_init_flag){
		LOGI(TAG,"sdcard not init successfully");
		return;
	}

	if ((ret = f_open(&file_s, path, FA_CREATE_ALWAYS | FA_WRITE)) != FR_OK) {
        LOGE(TAG,"open file %s err[%d]", path, ret);
        return;
    }

	LOGI(TAG,"Open %s ok", path);
	
	ret = f_write(&file_s,test_data ,strlen(test_data) , &ret_len);
	if(ret != FR_OK){
        LOGE(TAG,"write file %s err[%d]", path, ret);
		f_close(&file_s);
		return;
	}

	LOGI(TAG,"write file %s %d byte successful", path,ret_len);
	f_close(&file_s);

	if ((ret = f_open(&file_s, path, FA_READ)) != FR_OK) {
        LOGE(TAG,"open file %s err[%d]", path, ret);
        return;
    }
	
	ret = f_read(&file_s,(void *)read_buf, sizeof(read_buf) , &ret_len);
	if(ret != FR_OK){
		LOGE(TAG,"read file %s err[%d]", path, ret);
		f_close(&file_s);
		return;
	}
	LOGI(TAG,"read file %s %d byte successful", path, ret_len);
	for(int i = 0; i < ret_len; i++){
		LOGI(TAG,"read buf[%d]:%c(0x%x)",i,read_buf[i],read_buf[i]);
	}
	
	f_close(&file_s);
}

