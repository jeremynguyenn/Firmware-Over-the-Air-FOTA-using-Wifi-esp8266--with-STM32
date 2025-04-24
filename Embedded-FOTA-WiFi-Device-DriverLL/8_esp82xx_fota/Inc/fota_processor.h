#ifndef __FOTA_PROCESSOR_H
#define __FOTA_PROCESSOR_H
#include <stdio.h>
#include <stddef.h>
#include "esp82xx_lib.h"
#include "flash_driver.h"
#include "esp82xx_lib.h"


#define NEW_FIRMWARE_START_ADDRESS		0x08008000		//SECTOR 2
#define FIRMWARE "firmware_update.bin"

#define  MAX_FIRMWARE_SIZE		10500
#define  TEMP_RX_BUFF_SZ		11000
void firmware_update(void);
void jump_to_app(uint32_t address);


#endif
