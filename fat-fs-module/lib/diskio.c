/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "stdio.h"
#include "diskio.h"		/* FatFs lower layer API */
#include "sdcard.h"
#include "w25qxx.h"


/* Definitions of physical drive number for each drive */
#define M0		0	/* Example: Map MMC/SD card to physical drive 0 */
#define M1		1	/* Map FLASH card to physical drive 1*/

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status(BYTE pdrv)
{
	switch(pdrv){
		case M0:/*SD card*/
			return 0;
		case M1:/*FLASH*/
			return 0;
		default:
			return 0;
	}
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(BYTE pdrv)
{
	UINT i;
	DSTATUS status = STA_NOINIT;
	switch(pdrv){
		case M0:/*SD card*/
			if (sd_init() == 0)
				return 0;
			else
				return STA_NOINIT;
		case M1:/*FLASH*/
	//		w25qxx_init_dma(3,0);
	//		w25qxx_enable_quad_mode_dma();
	//		i = 500;
	//		while(--i);
			status = disk_status(pdrv);
			return status;
		default:
			return STA_NOINIT;
	}
}


/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count)
{
	switch(pdrv){
		case M0:
			if (sd_read_sector_dma(buff, sector, count) == 0)
				return RES_OK;
			else
				return RES_ERROR;
		case M1:
			/*偏移2048个扇区，即 2048*4096/1024/1024 = 8MB*/
			sector += 2048;
			if(w25qxx_read_data_dma(sector << 12, buff,count << 12, W25QXX_STANDARD) == W25QXX_OK)
				return RES_OK;
			else
				return RES_ERROR;
		default:
			return RES_ERROR;
			
	}
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

DRESULT disk_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count)
{
	uint32_t write_addr;

	switch(pdrv){
		case M0:
			if (sd_write_sector_dma((BYTE *)buff, sector, count) == 0)
				return RES_OK;
			else
				return RES_ERROR;
		case M1:
			/*偏移2048个扇区，即 2048*4096/1024/1024 = 8MB*/
			sector += 2048;
			write_addr = sector << 12;
			w25qxx_sector_erase_dma(write_addr);
			while(w25qxx_is_busy_dma() == W25QXX_BUSY);
			if(w25qxx_write_data_direct_dma(write_addr,(BYTE *)buff, count << 12) == W25QXX_OK)
			{
				// printf("write success!\n");
				return RES_OK;
			}	
			else
			{
				printf("write failed!\n");
				return RES_ERROR;
			}
			while(w25qxx_is_busy_dma() == W25QXX_BUSY);				
		default:
			return RES_ERROR;
	}
}

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/
DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
	DRESULT res = RES_ERROR;
	switch(pdrv){
		case M0:
			switch (cmd) {
				/* Make sure that no pending write process */
				case CTRL_SYNC:
					res = RES_OK;
					break;
				/* Get number of sectors on the disk (DWORD) */
				case GET_SECTOR_COUNT:
					*(DWORD *)buff = (cardinfo.SD_csd.DeviceSize + 1) << 10;
					res = RES_OK;
					break;
					/* Get R/W sector size (WORD) */
				case GET_SECTOR_SIZE:
					*(WORD *)buff = cardinfo.CardBlockSize;
					res = RES_OK;
					break;
				/* Get erase block size in unit of sector (DWORD) */
				case GET_BLOCK_SIZE:
					*(DWORD *)buff = cardinfo.CardBlockSize;
					res = RES_OK;
					break;
				default:
					res = RES_PARERR;
			}
			return res;
		case M1:
			switch (cmd) {
				/* Make sure that no pending write process */
				case CTRL_SYNC:
					res = RES_OK;
					break;
				/* Get number of sectors on the disk (DWORD) */
				/* 扇区数量：2560*4096/1024/1024=10(MB) */ 
				case GET_SECTOR_COUNT:
					*(DWORD *)buff = 2048;
					res = RES_OK;
					break;
					/* Get R/W sector size (WORD) */
				case GET_SECTOR_SIZE:
					*(WORD *)buff = 4096;
					res = RES_OK;
					break;
				/* Get erase block size in unit of sector (DWORD) */
				case GET_BLOCK_SIZE:
					*(DWORD *)buff = 1;
					res = RES_OK;
					break;
				default:
					res = RES_PARERR;
			}
			return res;
		default:
			return RES_PARERR;
	}
}

DWORD get_fattime(void)
{
	return ((DWORD)(2018-1980)<<25)
		   |	((DWORD)1<<21)
		   |	((DWORD)1<<16)
		   |	((DWORD)0<<11)
		   |	((DWORD)0<<5)
		   |	((DWORD)0<<1);
}
