/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdint.h>
#include <stm32f3xx_hal.h>
#include "stm32f3xx_hal_def.h"
#include "stm32f3xx_hal_spi.h"
#include "sd_driver.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum {
	OK = 0,
	TIMEOUT,
	ERR,
	FATAL
} sys_status_t;

typedef struct {
	float tmstp;
	float accel_x;
	float accel_y;
	float accel_z;
	float pressure;
	float temp;
} log_packet_t;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define MAX_RETRIES 0x1F4
#define LOG_BUFFER_SIZE sizeof(log_packet_t) * 6;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
sys_status_t storage_init();
sys_status_t sensor_init();
sys_status_t storage_error(int max_retries);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
#define STATUS_LED_PIN GPIO_PIN_1
#define STATUS_LED_PORT GPIOB
#define SD_CS_PIN GPIO_PIN_6
#define SD_CS_PORT GPIOA
#define ACCEL_CS_PIN GPIO_PIN_12
#define ACCEL_CS_PORT GPIOA
#define TEMP_CS_PIN GPIO_PIN_11
#define TEMP_CS_PORT GPIOA
#define BARO_CS_PIN GPIO_PIN_12
#define BARO_CS_PORT GPIOB

#define STATUS_LED_LOW()										\
	HAL_GPIO_WritePin(STATUS_LED_PORT, STATUS_LED_PIN, RESET)
#define STATUS_LED_HIGH()										\
	HAL_GPIO_WritePin(STATUS_LED_PORT, STATUS_LED_PIN, SET)
// delay 500 millis for fatal error
#define STATUS_FATAL_DELAY()									\
	HAL_Delay(500)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
