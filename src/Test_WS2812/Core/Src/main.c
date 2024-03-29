/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ws2812_SPI.h"
#include "maze.h"
#include "numbers.h"
#include "prng.h"
#include "lookup_table.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NUM_COLORS 18 // 16 pkg colors + black + wall
#define ANIMATION_DELAY_MS 30 // time in ms an animation should take

#define MAZE_WIDTH (WS2812_NUM_LEDS_X - 1)
#define MAZE_HEIGHT (WS2812_NUM_LEDS_Y - 1)

/// BEGIN MERGE TO PRODUCTION ///
// do-while(0) is a common trick to make a macro behave like a function
#define FIND_INDEX(array, size, element, result) \
do { \
    uint16_t found = 0; \
    for (uint16_t i = 0; i < size; ++i) { \
        if (array[i] == element) { \
            result = i; \
            found = 1; \
            break; \
        } \
    } \
    if (!found) result = -1; \
} while (0)
/// END MERGE TO PRODUCTION ///
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
DMA_HandleTypeDef hdma_tim2_ch3_up;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
enum
{
  C_BLACK,                              // do not change
  C_WHITE, C_RED, C_GREEN, C_BLUE,      // do not change
  C_CYAN, C_MAGENTA, C_YELLOW, C_BROWN, // do not change
  C_LIME, C_OLIVE, C_ORANGE, C_PINK,    // do not change
  C_PURPLE, C_TEAL, C_VIOLET, C_MAUVE,  // do not change
  C_WALL                                // add more colors as you see fit
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/// BEGIN MERGE TO PRODUCTION ///
void animateSend(void) {
	uint8_t i = 0;

	// find index of Lager, where packageId is stored
    FIND_INDEX(Lager, LAGER_SIZE, packageId, i);

	// skip any but first function call and if FIND_INDEX was unsuccesfull
	if (i < 0 || i >= LAGER_SIZE) return;

	// blink corresponding LED once
    pixels[i+1] = color[C_BLACK];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[LAGER_SIZE+1] = color[packageId];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[LAGER_SIZE+1] = color[C_BLACK];
	writeLEDs(pixels);

    // TODO: maze stuff
}

void animateReceive(void) {
	uint8_t i = 0;

	// find index of tempLager, where packageId is stored
    FIND_INDEX(tempLager, LAGER_SIZE, packageId, i);

	// skip any but first function call and if FIND_INDEX was unsuccesfull
	if (i < 0 || i >= LAGER_SIZE) return;

	// blink corresponding LED once
    pixels[0] = color[packageId];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[0] = color[C_BLACK];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[i+1] = color[packageId];
	writeLEDs(pixels);

    // TODO: maze stuff
}

void animateCreate(void) {
	uint8_t i = 0;

	// find index of tempLager, where packageId is stored
    FIND_INDEX(tempLager, LAGER_SIZE, packageId, i);

	// skip any but first function call and if FIND_INDEX was unsuccesfull
	if (i < 0 || i >= LAGER_SIZE) return;

	// blink corresponding LED once
    pixels[i+1] = color[packageId];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[i+1] = color[C_BLACK];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[i+1] = color[packageId];
	writeLEDs(pixels);
}
void animateDeliver(void) {
	uint8_t i = 0;

	// find index of Lager, where packageId is stored
    FIND_INDEX(Lager, LAGER_SIZE, packageId, i);

	// skip any but first function call and if FIND_INDEX was unsuccesfull
	if (i < 0 || i >= LAGER_SIZE) return;

	// blink corresponding LED once
    pixels[i+1] = color[C_BLACK];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[i+1] = color[packageId];
	writeLEDs(pixels);
	HAL_Delay(BLINK_TIME);
    pixels[i+1] = color[C_BLACK];
	writeLEDs(pixels);
}
/// END MERGE TO PRODUCTION ///
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  ColorRGB_t color[NUM_COLORS] = {
  /* B    R    G   */
    {0,   0,   0  }, // C_BLACK
    {255, 255, 255}, // C_WHITE
    {0,   255, 0  }, // C_RED
    {0,   0,   255}, // C_GREEN
    {255, 0,   0  }, // C_BLUE
    {255, 0,   255}, // C_CYAN
    {255, 255, 0  }, // C_MAGENTA
    {0,   255, 255}, // C_YELLOW
    {64,  191, 128}, // C_BROWN
    {0,   191, 255}, // C_LIME
    {0,   128, 128}, // C_OLIVE
    {0,   255, 128}, // C_ORANGE
    {191, 255, 191}, // C_PINK
    {64,  191, 0  }, // C_PURPLE
    {128, 0,   128}, // C_TEAL
    {128, 128, 0  }, // C_VIOLET
    {128, 128, 0  }, // C_MAUVE
    {4,   4,   4  }  // C_WALL
  };
  ColorRGB_t darkColor[NUM_COLORS] = {
  /*  B    R    G  */
  {  0,   0,   0 }, // C_BLACK
  { 16,  16,  16 }, // C_WHITE
  {  0,  16,   0 }, // C_RED
  {  0,   0,  16 }, // C_GREEN
  { 16,   0,   0 }, // C_BLUE
  { 16,   0,  16 }, // C_CYAN
  { 16,  16,   0 }, // C_MAGENTA
  {  0,  16,  16 }, // C_YELLOW
  {  4,  12,   8 }, // C_BROWN
  {  0,  12,  16 }, // C_LIME
  {  0,   8,   8 }, // C_OLIVE
  {  0,  16,   8 }, // C_ORANGE
  { 12,  16,  12 }, // C_PINK
  {  4,  12,   0 }, // C_PURPLE
  {  8,   0,   8 }, // C_TEAL
  {  8,   8,   0 }, // C_VIOLET
  {  8,   8,   0 }, // C_MAUVE
  {  1,   1,   1 }  // C_WALL
};
  //ColorRGB_t* pixel[WS2812_NUM_LEDS_Y][WS2812_NUM_LEDS_X] = {0}; // fill with &color[C_COLOR]
                                                                
  /* maze vars */
  uint8_t startX = 1;
  uint8_t startY = 0;
  uint8_t exitX = MAZE_WIDTH - 2;
  uint8_t exitY = MAZE_HEIGHT - 1;

  uint8_t packageID = 0;

  uint16_t i = 0, x = 0, y = 0; // index variables
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  SystemInit();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  ws2812_init();
  initMaze(&maze, MAZE_HEIGHT, MAZE_WIDTH, startX, startY, exitX, exitY);
  initPath(&path, MAZE_WIDTH * MAZE_HEIGHT);
  initPRNG(&rng, numbers, SIZE_NUMBERS);
  initLookupTable(&lookupTable, WS2812_NUM_LEDS_Y, WS2812_NUM_LEDS_X);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
	/* reset panel to black */
	ws2812_pixel_all(&color[C_BLACK]);

	/* set start and end point */
    startX++;
    if (startX == MAZE_WIDTH - 1) startX = 1;
    exitX--;
    if (exitX == 0) exitX = MAZE_WIDTH - 2;

    /* set package color */
    packageID = C_GREEN;

	/* set new start and exit */
    maze.start.x = startX; maze.start.y = startY;
    maze.exit.x = exitX; maze.exit.y = exitY;

	/* generate and solve maze */
	generateMaze(&maze);
	solveMaze(&maze, &path);

	/* write maze */
	for (x = 0; x < MAZE_WIDTH; x++)
	{
	  for (y = 0; y < MAZE_HEIGHT; y++)
	  {
	    if (maze.grid[y][x] == WALL) ws2812_pixel(x, y, &color[C_WALL]);
	  }
	}

	/* write solution */
	for (i = path.size - 1; i >= 1; i--)
	{
      // HOTFIX: write start point at first iteration since it missing in path
      if (i == path.size - 1)
      {
        ws2812_pixel(startX, startY, &color[packageID]);
        HAL_Delay(ANIMATION_DELAY_MS);
        ws2812_pixel(startX, startY, &darkColor[packageID]);
      }
      if (path.p[i].x != 0 && path.p[i].y != 0)
      {
        ws2812_pixel(path.p[i].x, path.p[i].y, &color[packageID]); // TODO: start point is not in path
        HAL_Delay(ANIMATION_DELAY_MS);
        ws2812_pixel(path.p[i].x, path.p[i].y, &darkColor[packageID]);
      }
	}

    HAL_Delay(5*ANIMATION_DELAY_MS);

    /* reset */
    resetMaze(&maze, startX, startY, exitX, exitY);
    resetPath(&path);
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
