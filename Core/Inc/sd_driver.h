/** *******************************************
 * 				SD DRIVER HEADER
 * ********************************************/


#ifndef __CORE_INC_SD_DRIVER_H
#define __CORE_INC_SD_DRIVER_H

// Includes
#include "main.h"

// Globals


// GPIO Definitions
#define SD_CS_LOW()										\
	HAL_GPIO_WritePin(SD_CS_PORT, SD_CS_PIN, RESET)
#define SD_CS_HIGH()									\
	HAL_GPIO_WritePin(SD_CS_PORT, SD_CS_PIN, SET)


// State Definitions
typedef enum {
	SD_OK = 0,
	SD_TIMEOUT,
	SD_SPI_ERR,
	SD_CRC_ERR,
	SD_PARSE_ERR,
	SD_NO_FIX
} sd_status_t;


typedef struct {

} sd_packet_t;

// Fucntion Prototypes
sd_status_t sd_init(BYTE drv);
sd_status_t sd_status(BYTE drv);


#endif /* __CORE_INC_SD_DRIVER_H */
