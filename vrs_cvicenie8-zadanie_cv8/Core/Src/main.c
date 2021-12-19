/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


int index_1 = 0;
int index_2 = 0;
int num = 0;
int smer = 0;
char meno[30] = "JURAJ_GREGUS_98331";



const unsigned char seven_seg_digits_decode_abcdefg[75]= {
/*  0     1     2     3     4     5     6     7     8     9     :     ;     */
    0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0x00, 0x00,
/*  <     =     >     ?     @     A     B     C     D     E     F     G     */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x1F, 0x4E, 0x3D, 0x4F, 0x47, 0x5E,
/*  H     I     J     K     L     M     N     O     P     Q     R     S     */
    0x37, 0x06, 0x3C, 0x57, 0x0E, 0x55, 0x15, 0x1D, 0x67, 0x73, 0x05, 0x5B,
/*  T     U     V     W     X     Y     Z     [     \     ]     ^     _     */
    0x0F, 0x3E, 0x1C, 0x5C, 0x13, 0x3B, 0x6D, 0x00, 0x00, 0x00, 0x00, 0x08,
/*  `     a     b     c     d     e     f     g     h     i     j     k     */
    0x00, 0x77, 0x1F, 0x4E, 0x3D, 0x4F, 0x47, 0x5E, 0x37, 0x06, 0x3C, 0x57,
/*  l     m     n     o     p     q     r     s     t     u     v     w     */
    0x0E, 0x55, 0x15, 0x1D, 0x67, 0x73, 0x05, 0x5B, 0x0F, 0x3E, 0x1C, 0x5C,
/*  x     y     z     */
    0x13, 0x3B, 0x6D
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* System interrupt init*/
  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  LL_TIM_EnableCounter(TIM2);
  LL_TIM_EnableIT_UPDATE(TIM2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1){
	  if(smer){
		  	  for (index_2 = strlen(meno) - 4; index_2 >= 0; index_2--){
		  			LL_mDelay(500);
		  			if(index_2==0){
						 smer = 0;
						 break;
		  			}
		  	   }
	  	  }
	  if(!smer){
		  for (index_2 = 0; index_2 <= strlen(meno) - 4; index_2++){
		  			  LL_mDelay(500);
		  			  if( index_2 == (strlen(meno)-4)){
		  				  smer = 1;
		  				  break;
		  			  }
		  }
	  }
  }
}
/* USER CODE END WHILE */
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_Init1msTick(8000000);
  LL_SetSystemCoreClock(8000000);
}

/* USER CODE BEGIN 4 */
unsigned char decode_7seg(unsigned char chr){

	if (chr > (unsigned char)'z')
        return 0x00;
    return seven_seg_digits_decode_abcdefg[chr - '0'];
}

/**
 * displayData() -> Conversion of char to hex.
 */
void displayData(char chr)
{

	uint8_t transfer,help_var;
	transfer = decode_7seg(chr);
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	transfer = transfer >> 1;
	help_var = transfer & 1;
	if(help_var)
			LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);

}
/*
 * Turns required digit ON
 */


/**
 * Display data in dDisplayData.
 * Sets every digit to display its value and decimal point.
 */
void updateDisplay(void)
{
	resetDigits();
	resetSegments();
	setDigit(num);
	displayData(meno[index_1+index_2]);
}


void setDigit(uint8_t pos)
{
	if(pos == 0){
		DIGIT_1_ON;
	}
	else if(pos == 1){
		DIGIT_2_ON;
	}
	else if(pos == 2){
		DIGIT_3_ON;
	}
	else if(pos == 3){
		DIGIT_4_ON;
	}
}



/*Reset (turn-off) all the segments of display*/
void resetSegments(void)
{
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_3);
}


/* Reset (turn-off) all digits*/
void resetDigits(void)
{
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);
}

//Update displayed data and keep display ON
void TIM2_IRQHandler(void)
{
	if(LL_TIM_IsActiveFlag_UPDATE(TIM2))
	{
		if(num > 3)
				num = 0;
		if(index_1 > 3)
				index_1 = 0;
		updateDisplay();
		num++;
		index_1++;
	}
	LL_TIM_ClearFlag_UPDATE(TIM2);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
