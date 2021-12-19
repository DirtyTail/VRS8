/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_ll_cortex.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_pwr.h"
#include "stm32f3xx_ll_dma.h"
#include "stm32f3xx_ll_tim.h"
#include "stm32f3xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#define SEGMENTA_PIN	LL_GPIO_PIN_1
#define SEGMENTA_PORT	GPIOA

#define SEGMENTB_PIN	LL_GPIO_PIN_0
#define SEGMENTB_PORT	GPIOA

#define SEGMENTC_PIN	LL_GPIO_PIN_8
#define SEGMENTC_PORT	GPIOA

#define SEGMENTD_PIN	LL_GPIO_PIN_5
#define SEGMENTD_PORT	GPIOB

#define SEGMENTE_PIN 	LL_GPIO_PIN_11
#define SEGMENTE_PORT	GPIOA

#define SEGMENTF_PIN 	LL_GPIO_PIN_3
#define SEGMENTF_PORT	GPIOA

#define SEGMENTG_PIN	LL_GPIO_PIN_4
#define SEGMENTG_PORT	GPIOB

#define SEGMENTDP_PIN	LL_GPIO_PIN_1
#define SEGMENTDP_PORT	GPIOB

#define DIGIT_1_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_2_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_3_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_4_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define DIGIT_TIME_ON	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7)


unsigned char decode_7seg(unsigned char chr);
void setDigit(uint8_t pos);
void resetDigits(void);
void resetSegments(void);
void updateDisplay(void);
void displayData(char c);
void TIM2_IRQHandler(void);
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
#define B_Pin LL_GPIO_PIN_0
#define B_GPIO_Port GPIOA
#define A_Pin LL_GPIO_PIN_1
#define A_GPIO_Port GPIOA
#define DIG3_Pin LL_GPIO_PIN_2
#define DIG3_GPIO_Port GPIOA
#define F_Pin LL_GPIO_PIN_3
#define F_GPIO_Port GPIOA
#define DIG1_Pin LL_GPIO_PIN_4
#define DIG1_GPIO_Port GPIOA
#define DIG0_Pin LL_GPIO_PIN_5
#define DIG0_GPIO_Port GPIOA
#define DIG2_Pin LL_GPIO_PIN_6
#define DIG2_GPIO_Port GPIOA
#define DIGT_Pin LL_GPIO_PIN_7
#define DIGT_GPIO_Port GPIOA
#define DP_Pin LL_GPIO_PIN_1
#define DP_GPIO_Port GPIOB
#define C_Pin LL_GPIO_PIN_8
#define C_GPIO_Port GPIOA
#define E_Pin LL_GPIO_PIN_11
#define E_GPIO_Port GPIOA
#define G_Pin LL_GPIO_PIN_4
#define G_GPIO_Port GPIOB
#define D_Pin LL_GPIO_PIN_5
#define D_GPIO_Port GPIOB
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
