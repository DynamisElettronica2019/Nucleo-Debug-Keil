/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define UserButton_Pin GPIO_PIN_13
#define UserButton_GPIO_Port GPIOC
#define GEAR_MOTOR_IS1_Pin GPIO_PIN_0
#define GEAR_MOTOR_IS1_GPIO_Port GPIOC
#define GEAR_MOTOR_IS2_Pin GPIO_PIN_1
#define GEAR_MOTOR_IS2_GPIO_Port GPIOC
#define CLUTCH_SERVO_SENSE_FIL_Pin GPIO_PIN_4
#define CLUTCH_SERVO_SENSE_FIL_GPIO_Port GPIOA
#define H20_FAN_SX_SENSE_FIL_Pin GPIO_PIN_5
#define H20_FAN_SX_SENSE_FIL_GPIO_Port GPIOA
#define H20_FAN_DX_SENSE_FIL_Pin GPIO_PIN_6
#define H20_FAN_DX_SENSE_FIL_GPIO_Port GPIOA
#define H20_PUMP_SENSE_FIL_Pin GPIO_PIN_7
#define H20_PUMP_SENSE_FIL_GPIO_Port GPIOA
#define FUEL_PUMP_SENSE_FIL_Pin GPIO_PIN_4
#define FUEL_PUMP_SENSE_FIL_GPIO_Port GPIOC
#define TEMP_SENSE_Pin GPIO_PIN_5
#define TEMP_SENSE_GPIO_Port GPIOC
#define GreenLed_Pin GPIO_PIN_0
#define GreenLed_GPIO_Port GPIOB
#define CURRENT_SENSE_Pin GPIO_PIN_1
#define CURRENT_SENSE_GPIO_Port GPIOB
#define LED_5_ROSSO_Pin GPIO_PIN_13
#define LED_5_ROSSO_GPIO_Port GPIOF
#define LED_4_GIALLO_Pin GPIO_PIN_14
#define LED_4_GIALLO_GPIO_Port GPIOE
#define LED_3_GIALLO_Pin GPIO_PIN_15
#define LED_3_GIALLO_GPIO_Port GPIOE
#define LED_2_GIALLO_Pin GPIO_PIN_10
#define LED_2_GIALLO_GPIO_Port GPIOB
#define LED_1_GIALLO_Pin GPIO_PIN_11
#define LED_1_GIALLO_GPIO_Port GPIOB
#define RedLed_Pin GPIO_PIN_14
#define RedLed_GPIO_Port GPIOB
#define BlueLed_Pin GPIO_PIN_7
#define BlueLed_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
