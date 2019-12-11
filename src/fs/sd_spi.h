#ifndef _SD_SPI_H_
#define _SD_SPI_H_

/*
 * @brief  初始化sd card信息.
 * @param  None
 * @retval :
 *         - 0xFF: 初始化失败
 *         - 0: 初始化成功，可由cardinfo获取SD card信息
 */
int sdcard_init(void);
void sdcard_test();

#endif /*_SD_SPI_H_*/

