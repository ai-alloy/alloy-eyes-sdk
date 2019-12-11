#ifndef _FLASH_SPI_H_
#define _FLASH_SPI_H_

/*
 * @brief  初始化flash驱动和文件系统.
 * @param  None
 * @retval :
 *         - 0xFF: 初始化失败
 *         - 0: 初始化成功
 */
int flash_init_ex();
void flash_test();
 
#endif /*_FLASH_SPI_H_*/

