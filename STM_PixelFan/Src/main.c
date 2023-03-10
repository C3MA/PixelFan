/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SPI_DMA.h"
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
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi1_tx;
DMA_HandleTypeDef hdma_spi2_rx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim15;

/* USER CODE BEGIN PV */

#define LINES_PER_ROUND 180		//255
#define LINES_DIFF ((LINES_PER_ROUND / 3) * 26)
#define LEDS_PER_LINE 26
#define LINE_ZERO_OFFSET 95	     //lower values = rotate clockwise, bigger value = rotate counter clockwise
#define IMAGE_BUFF_SIZE LINES_PER_ROUND*LEDS_PER_LINE

uint8_t frameStart[4] = {0,0,0,0};
uint8_t frameEnd[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
uint8_t ledBuff[IMAGE_BUFF_SIZE][4];
uint32_t line_index[3];

uint8_t state = 0;
uint8_t linePos = 0;
uint8_t dmaRunning = 0;
uint32_t globCnt = 0;
uint32_t regCnt = 0;
uint32_t periodAvg = 0;
volatile uint32_t roundComplete = 0;
volatile uint32_t roundSetToZero = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM15_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void clearAllLEDs();
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

	//fill buffer:
	for(uint32_t i = 0; i < IMAGE_BUFF_SIZE; i++)
	{
		ledBuff[i][0] = 0xFF;
		if(i < (IMAGE_BUFF_SIZE/2) + 13)
		{
			ledBuff[i][1] = 6;
			ledBuff[i][2] = 0;
			ledBuff[i][3] = 0;
		}
		else
		{
			ledBuff[i][1] = 0;
			ledBuff[i][2] = 6;
			ledBuff[i][3] = 0;
		}
	}

	line_index[0] = 2*LINES_DIFF;
	line_index[1] = LINES_DIFF;
	line_index[2] = 0;



  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_TIM15_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  clearAllLEDs();

  HAL_Delay(100);

  spi2DmaStart((uint8_t*)ledBuff, IMAGE_BUFF_SIZE*4);	//Start DMA for receiving ESP Data

  HAL_TIM_Base_Start_IT(&htim15);

  HAL_TIM_Base_Start(&htim1);
  TIM1->DIER |= TIM_DIER_CC1IE;
  TIM1->CCER |= TIM_CCER_CC1E;
  TIM1->SMCR |= (0b101 << 4);	//TI1FP1 selected as trigger
  TIM1->SMCR |= 0b100;			//rising edge resets counter
  TIM1->CCMR1 |= (0b1111 << 4);//IC1F Filter
  TIM1->SR = 0;	//Clear all Interrupts

  //uint32_t oldGPIOA = 0;

  while (1)
  {
	  /*if((GPIOA->IDR & (1 << 8)))
	  {
		ledBuff[2][1] = 0;
		ledBuff[2][2] = 0;
		ledBuff[2][3] = 60;
	  }
	  else
	  {
		ledBuff[2][1] = 0;
		ledBuff[2][2] = 0;
		ledBuff[2][3] = 0;
	  }*/
/*
	  if((GPIOA->IDR & (1 << 8)) != oldGPIOA)
	  {
		  if(oldGPIOA != 0)
		  {

				//line_index[0] = 2*LINES_DIFF;
				//line_index[1] = LINES_DIFF;
				//line_index[2] = 0;
			  if(line_index[0] > IMAGE_BUFF_SIZE / 2)
			  {
				  if(TIM15->ARR < 420)
					  TIM15->ARR++;
			  }
			  else
			  {
				  if(TIM15->ARR > 400)
					  TIM15->ARR--;
			  }
		  }

		  oldGPIOA = GPIOA->IDR & (1 << 8);
	  }
*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage 
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the peripherals clocks 
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_TIM15|RCC_PERIPHCLK_TIM1;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLKSOURCE_PCLK1;
  PeriphClkInit.Tim15ClockSelection = RCC_TIM15CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */
	__HAL_RCC_SPI1_CLK_ENABLE();
  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_SLAVE;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES_RXONLY;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */
  //HAL_NVIC_SetPriority(SPI2_IRQn, 0, 0);
  //HAL_NVIC_EnableIRQ(SPI2_IRQn);

  //SPI2->CR2 |= SPI_CR2_RXNEIE;
  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */
	//__HAL_RCC_TIM1_CLK_ENABLE();
  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 127;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0xFFFF;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM15 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM15_Init(void)
{

  /* USER CODE BEGIN TIM15_Init 0 */

  /* USER CODE END TIM15_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM15_Init 1 */

  /* USER CODE END TIM15_Init 1 */
  htim15.Instance = TIM15;
  htim15.Init.Prescaler = 3;
  htim15.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim15.Init.Period = 4700;
  htim15.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim15.Init.RepetitionCounter = 0;
  htim15.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim15) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim15, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_OC_Init(&htim15) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim15, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 50;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_OC_ConfigChannel(&htim15, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim15, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM15_Init 2 */

  /* USER CODE END TIM15_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void TIM15_PeriodElapsedCallback()
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);

	//return;
	if(dmaRunning == 0)// && roundComplete == 0)
	{
		spiDmaStartTransmission(frameStart, 4);
		//HAL_SPI_Transmit_DMA(&hspi1, frameStart, 4);
		dmaRunning = 1;

		if(roundSetToZero == 1)
		{
			//if(line_index[2] - 2 > ((LEDS_PER_LINE*LINE_ZERO_OFFSET)-26) || line_index[2] + 2 < ((LEDS_PER_LINE*LINE_ZERO_OFFSET)-26))
			{
				line_index[2] = (LEDS_PER_LINE*LINE_ZERO_OFFSET)-26;
				line_index[0] = line_index[2] + 2*LINES_DIFF-26;
				line_index[1] = line_index[2] + LINES_DIFF-26;
			}
			roundSetToZero = 0;
		}
	}

}

void SPI_DMA_Irq()
{
	DMA1->IFCR |= DMA_IFCR_CTCIF1;		//clear interrupts
	DMA1->IFCR |= DMA_IFCR_CGIF1;		//clear interrupts
	DMA1->IFCR |= DMA_IFCR_CHTIF1;
	DMA1->IFCR |= DMA_IFCR_CTEIF1;


	if(state == 0)
	{
		spiDmaStartTransmission(&ledBuff[line_index[linePos]][0], (uint16_t)(4*26));

		linePos++;

		if(linePos == 3)
		{
			state = 1;
		}
	}
	else if(state == 1)
	{
		spiDmaStartTransmission(frameEnd, 5);
		state = 2;
	}
	else if(state == 2)
	{
		linePos = 0;
		state = 0;
		dmaRunning = 0;

		line_index[0]+=26;
		line_index[1]+=26;
		line_index[2]+=26;

		if(line_index[0] >= IMAGE_BUFF_SIZE) line_index[0] -= IMAGE_BUFF_SIZE;
		if(line_index[1] >= IMAGE_BUFF_SIZE) line_index[1] -= IMAGE_BUFF_SIZE;
		if(line_index[2] >= IMAGE_BUFF_SIZE) line_index[2] -= IMAGE_BUFF_SIZE;
	}

}

void SPI2_ESP_IRQ()
{
	static uint32_t pnt = 0;
	static uint32_t subPnt = 0;
	SPI2->CR1 |= SPI_CR1_SSI;
	uint8_t data;

	//ledBuff[oldSpiData][2] = 0;

	while(((SPI2->SR & SPI_SR_FRLVL) >> SPI_SR_FRLVL_Pos) > 0)
	{
		//read all Data
		data = SPI2->DR;

		ledBuff[pnt][subPnt] = data;

		subPnt++;

		if(subPnt == 4)
		{
			subPnt = 0;
			pnt++;

			if(pnt == IMAGE_BUFF_SIZE)
			{
				pnt = 0;
			}
		}
	}

	SPI2->CR1 &= ~SPI_CR1_SSI;
}

void TIM1_InputCapture_IRQ()
{
	//One round complete (Input Capture triggered from Hallsensor)

	uint32_t period = TIM1->CCR1;

	roundSetToZero = 1;

	periodAvg += period;

	regCnt++;
	if(regCnt == 32)
	{
		//periodAvg = (periodAvg << 0);	//Durch 32 f??r Mittelung, Mal 32 f??r gleiche Zeitbasis => Mal 1

		periodAvg /= LINES_PER_ROUND;

		if(periodAvg > 3500 && periodAvg < 65000)
		{
			TIM15->ARR = periodAvg-2;
			ledBuff[0][3] = 0;
			ledBuff[0][2] = 150;
		}
		else
		{
			ledBuff[0][2] = 0;
			ledBuff[0][3] = 150;
		}

		regCnt = 0;
		periodAvg = 0;
	}


}

void SPI2_DMA_Irq()	//SPI vom ESP
{
	//restart DMA
	spi2DmaStart((uint8_t*)ledBuff, IMAGE_BUFF_SIZE*4);
}

void clearAllLEDs()
{
	uint8_t tmpBuf[4] = {0,0,0,0};
	HAL_SPI_Transmit(&hspi1, tmpBuf, 4, HAL_MAX_DELAY);

	tmpBuf[0] = 0xFF;

	for(int i = 1; i <= 83; i++)
	{
	  HAL_SPI_Transmit(&hspi1, tmpBuf, 4, HAL_MAX_DELAY);
	}

	HAL_Delay(10);
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
