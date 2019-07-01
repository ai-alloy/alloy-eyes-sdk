#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "fpioa.h"
#include "utils.h"
#include "sysctl.h"
#include "math.h"
#include "syslog.h"
#include "gpiohs.h"
#include "gpio.h"

#include "w25qxx.h"
#include "ff.h"

/*
*对FLASH的操作，FLASH使用的是16MB的大小，目前只挂载后面8MB到文件系统上，前面8MB是系统保留使用。
*
*/
static bool flash_init_flag = false;
static const char *TAG = "FLASH-SPI";

/*flash的初始化*/
static int flash_init(void)
{
    uint8_t manuf_id, device_id;
    uint8_t spi_index = 3;

    w25qxx_init_dma(spi_index,0);
    w25qxx_enable_quad_mode_dma();
    w25qxx_read_id_dma(&manuf_id, &device_id);
    LOGI(TAG, "manuf_id:0x%02x, device_id:0x%02x", manuf_id, device_id);
    if ((manuf_id != 0xEF && manuf_id != 0xC8) || (device_id != 0x17 && device_id != 0x16))
    {
        LOGE(TAG, "flash test failed!");
        return -1;
    }

    return 0;
}

/*flash挂载到文件系统*/
static int flash_spi_init(void)
{
    static FATFS flash_fs;
    FRESULT status;
    DIR dj;
    FILINFO fno;
    BYTE work[4096];

    status = f_mount(&flash_fs, _T("1:"), 1);
    LOGI(TAG, "mount flash:%d", status);
    if (status == FR_NO_FILESYSTEM)
    {
        LOGI(TAG, "Flash no filesystem,Formatting......");
        status = f_mkfs(_T("1:"),FM_ANY,0,work,sizeof(work));
        if(status == FR_OK)
        {
            LOGI(TAG, "mkfs success,mount fs!");
            status = f_mount(NULL,_T("1:"),1);
            status = f_mount(&flash_fs,_T("1:"),1);
			LOGI(TAG, "mount flash again:%d", status);
        }
        else
        {
            LOGE(TAG, "flash mkfs failed!");
        }
    }
    else if(status != FR_OK)
    {
        LOGE(TAG, "flash mount filesystem failed,err:%d",status);
    }
    else
    {
        LOGI(TAG, "flash mount filesystem success!");
    }

    LOGI(TAG, "printf filename");
    status = f_findfirst(&dj, &fno, _T("1:"), _T("*"));
    while (status == FR_OK && fno.fname[0]) {
        if (fno.fattrib & AM_DIR){
            //LOGI(TAG, "dir:%s", fno.fname);
        }else{
            LOGI(TAG, "file:%s", fno.fname);
        }
        status = f_findnext(&dj, &fno);
    }
    f_closedir(&dj);
	
    return 0;
}

int flash_init_ex()
{
	if(flash_init())
    {
       LOGE(TAG, "flash test err!");
       return -1;
    }  
	if(flash_spi_init())
    {
       LOGE(TAG, "flash fs test err!");
        return -1;
    }
	flash_init_flag = true;
	return 0;
}

typedef struct{
    int a;
    int b;
    int c;
}data_test_t;

#define FLASH_DATA_TEST_NAME "1:text.txt"

static bool save_data(data_test_t* data)
{	
	FRESULT ret = FR_OK;
	FIL file_s;
	uint32_t ret_len = 0;
    const char *path = _T(FLASH_DATA_TEST_NAME);

	if ((ret = f_open(&file_s, path, FA_CREATE_ALWAYS | FA_WRITE)) != FR_OK) {
        LOGE(TAG, "open file %s err[%d]", path, ret);
		f_close(&file_s);
        return false;
    }

	LOGI(TAG, "Open %s ok", path);
	
	ret = f_write(&file_s,(void *)data ,sizeof(data_test_t) , &ret_len);
	if(ret != FR_OK){
        LOGE(TAG, "write file %s err[%d]", path, ret);
		f_close(&file_s);
		return false;
	}

	LOGI(TAG, "write file %s %d byte successful", path,ret_len);
	f_close(&file_s);

	return true;
}

static bool read_data(data_test_t* data)
{
    FRESULT ret = FR_OK;
	FIL file_s;
	uint32_t ret_len = 0;
    const char *path = _T(FLASH_DATA_TEST_NAME);

	if ((ret = f_open(&file_s, path, FA_READ)) != FR_OK) {
        LOGE(TAG, "open file %s err[%d]", path, ret);
		f_close(&file_s);
        return false;
    }
	
	LOGI(TAG, "Open %s ok", path);
	
	ret = f_read(&file_s,(void *)data, sizeof(data_test_t) , &ret_len);
	if(ret != FR_OK){
		LOGE(TAG, "read file %s err[%d]", path, ret);
		f_close(&file_s);
		return false;
	}
	LOGI(TAG, "read file %s %d byte successful", path, ret_len);
	
	f_close(&file_s);
	
	return true;
}

static FRESULT delete_file(const TCHAR *path)
{
	FRESULT ret;
	
	ret = f_unlink(path);
	if(ret != FR_OK){
		LOGE(TAG, "delete %s failed", path);
	}else{
		LOGI(TAG, "delete %s successfully", path);
	}
	return ret;
}

/*FLASH读写删操作*/
void flash_test()
{
	data_test_t data;

    //read
    if(!read_data(&data)){
        data.a = 0;
        data.b = 1;
        data.c = 2;
		LOGE(TAG, "fs read test failed");
    }else{
        if(data.a < 0)
            data.a = 0;
        if(data.b < 0)
            data.b = 1;
        if(data.c < 0)
            data.c = 2;
        LOGI(TAG, "Read data success, a:%d, b:%d, c:%d",data.a,data.b,data.c);
    }
	
    //write
    ++data.a;
    ++data.b;
    ++data.c;
    if(!save_data(&data)){
        LOGE(TAG, "Save Data failed");
		return;
    }else{
        LOGI(TAG, "Save data success, a:%d, b:%d, c:%d",data.a,data.b,data.c);
    }
	
    //read
    memset(&data,0,sizeof(data_test_t));
    if(!read_data(&data)){
        LOGE(TAG, "Read data failed");
		return;
    }else{
        LOGI(TAG, "Read data success, a:%d, b:%d, c:%d",data.a,data.b,data.c);
    }

	/*读写测试完删除文件*/
	delete_file(_T(FLASH_DATA_TEST_NAME));
}

