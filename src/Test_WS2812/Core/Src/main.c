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
#include "math.h"
#include "string.h"

#include "ws2812_SPI.h"
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
SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
DMA_HandleTypeDef hdma_tim2_ch3_up;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

uint8_t DMA_busy = 0;

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
/*
void ws2812_init(void);
void ws2812_send_spi(void);
void ws2812_pixel(uint16_t led_no, uint8_t r, uint8_t g, uint8_t b);
void ws2812_pixel_all(uint8_t r, uint8_t g, uint8_t b);

void ws2812_init(void) {
    memset(ws2812_buffer, 0, WS2812_BUFFER_SIZE);
    DMA_busy = 1;
    HAL_SPI_Transmit_DMA(&hspi2, ws2812_buffer, WS2812_BUFFER_SIZE);
}

#define WS2812_FILL_BUFFER(COLOR) \
    for( uint8_t mask = 0x80; mask; mask >>= 1 ) { \
        if( COLOR & mask ) { \
            *ptr++ = 0xfc; \
        } else { \
            *ptr++ = 0x80; \
        } \
    }

void ws2812_pixel(uint16_t led_no, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t * ptr = &ws2812_buffer[24 * led_no];
    WS2812_FILL_BUFFER(g);
    WS2812_FILL_BUFFER(r);
    WS2812_FILL_BUFFER(b);
}

void ws2812_pixel_all(uint8_t r, uint8_t g, uint8_t b) {
    uint8_t * ptr = ws2812_buffer;
    for( uint16_t i = 0; i < WS2812_NUM_LEDS; ++i) {
        WS2812_FILL_BUFFER(g);
        WS2812_FILL_BUFFER(r);
        WS2812_FILL_BUFFER(b);
    }
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef * hspi)
{
    HAL_SPI_Transmit_DMA(&hspi2, ws2812_buffer, WS2812_BUFFER_SIZE);
}*/

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
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* this is ugly but it is fast and saves RAM */
  uint16_t lookup_table[24][40] = {

        /* x:  0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35   36   37   38   39 */
  /*  y */
  /*  0 */ {   0,   1,   2,   3,   4, 120, 121, 122, 123, 124, 240, 241, 242, 243, 244, 360, 361, 362, 363, 364, 480, 481, 482, 483, 484, 600, 601, 602, 603, 604, 720, 721, 722, 723, 724, 840, 841, 842, 843, 844 },
  /*  1 */ {   5,   6,   7,   8,   9, 125, 126, 127, 128, 129, 245, 246, 247, 248, 249, 365, 366, 367, 368, 369, 485, 486, 487, 488, 489, 605, 606, 607, 608, 609, 725, 726, 727, 728, 729, 845, 846, 847, 848, 849 },
  /*  2 */ {  10,  11,  12,  13,  14, 130, 131, 132, 133, 134, 250, 251, 252, 253, 254, 370, 371, 372, 373, 374, 490, 491, 492, 493, 494, 610, 611, 612, 613, 614, 730, 731, 732, 733, 734, 850, 851, 852, 853, 854 },
  /*  3 */ {  15,  16,  17,  18,  19, 135, 136, 137, 138, 139, 255, 256, 257, 258, 259, 375, 376, 377, 378, 379, 495, 496, 497, 498, 499, 615, 616, 617, 618, 619, 735, 736, 737, 738, 739, 855, 856, 857, 858, 859 },
  /*  4 */ {  20,  21,  22,  23,  24, 140, 141, 142, 143, 144, 260, 261, 262, 263, 264, 380, 381, 382, 383, 384, 500, 501, 502, 503, 504, 620, 621, 622, 623, 624, 740, 741, 742, 743, 744, 860, 861, 862, 863, 864 },
  /*  5 */ {  25,  26,  27,  28,  29, 145, 146, 147, 148, 149, 265, 266, 267, 268, 269, 385, 386, 387, 388, 389, 505, 506, 507, 508, 509, 625, 626, 627, 628, 629, 745, 746, 747, 748, 749, 865, 866, 867, 868, 869 },
  /*  6 */ {  30,  31,  32,  33,  34, 150, 151, 152, 153, 154, 270, 271, 272, 273, 274, 390, 391, 392, 393, 394, 510, 511, 512, 513, 514, 630, 631, 632, 633, 634, 750, 751, 752, 753, 754, 870, 871, 872, 873, 874 },
  /*  7 */ {  35,  36,  37,  38,  39, 155, 156, 157, 158, 159, 275, 276, 277, 278, 279, 395, 396, 397, 398, 399, 515, 516, 517, 518, 519, 635, 636, 637, 638, 639, 755, 756, 757, 758, 759, 875, 876, 877, 878, 879 },
  /*  8 */ {  40,  41,  42,  43,  44, 160, 161, 162, 163, 164, 280, 281, 282, 283, 284, 400, 401, 402, 403, 404, 520, 521, 522, 523, 524, 640, 641, 642, 643, 644, 760, 761, 762, 763, 764, 880, 881, 882, 883, 884 },
  /*  9 */ {  45,  46,  47,  48,  49, 165, 166, 167, 168, 169, 285, 286, 287, 288, 289, 405, 406, 407, 408, 409, 525, 526, 527, 528, 529, 645, 646, 647, 648, 649, 765, 766, 767, 768, 769, 885, 886, 887, 888, 889 },
  /* 10 */ {  50,  51,  52,  53,  54, 170, 171, 172, 173, 174, 290, 291, 292, 293, 294, 410, 411, 412, 413, 414, 530, 531, 532, 533, 534, 650, 651, 652, 653, 654, 770, 771, 772, 773, 774, 890, 891, 892, 893, 894 },
  /* 11 */ {  55,  56,  57,  58,  59, 175, 176, 177, 178, 179, 295, 296, 297, 298, 299, 415, 416, 417, 418, 419, 535, 536, 537, 538, 539, 655, 656, 657, 658, 659, 775, 776, 777, 778, 779, 895, 896, 897, 898, 899 },
  /* 12 */ {  60,  61,  62,  63,  64, 180, 181, 182, 183, 184, 300, 301, 302, 303, 304, 420, 421, 422, 423, 424, 540, 541, 542, 543, 544, 660, 661, 662, 663, 664, 780, 781, 782, 783, 784, 900, 901, 902, 903, 904 },
  /* 13 */ {  65,  66,  67,  68,  69, 185, 186, 187, 188, 189, 305, 306, 307, 308, 309, 425, 426, 427, 428, 429, 545, 546, 547, 548, 549, 665, 666, 667, 668, 669, 785, 786, 787, 788, 789, 905, 906, 907, 908, 909 },
  /* 14 */ {  70,  71,  72,  73,  74, 190, 191, 192, 193, 194, 310, 311, 312, 313, 314, 430, 431, 432, 433, 434, 550, 551, 552, 553, 554, 670, 671, 672, 673, 674, 790, 791, 792, 793, 794, 910, 911, 912, 913, 914 },
  /* 15 */ {  75,  76,  77,  78,  79, 195, 196, 197, 198, 199, 315, 316, 317, 318, 319, 435, 436, 437, 438, 439, 555, 556, 557, 558, 559, 675, 676, 677, 678, 679, 795, 796, 797, 798, 799, 915, 916, 917, 918, 919 },
  /* 16 */ {  80,  81,  82,  83,  84, 200, 201, 202, 203, 204, 320, 321, 322, 323, 324, 440, 441, 442, 443, 444, 560, 561, 562, 563, 564, 680, 681, 682, 683, 684, 800, 801, 802, 803, 804, 920, 921, 922, 923, 924 },
  /* 17 */ {  85,  86,  87,  88,  89, 205, 206, 207, 208, 209, 325, 326, 327, 328, 329, 445, 446, 447, 448, 449, 565, 566, 567, 568, 569, 685, 686, 687, 688, 689, 805, 806, 807, 808, 809, 925, 926, 927, 928, 929 },
  /* 18 */ {  90,  91,  92,  93,  94, 210, 211, 212, 213, 214, 330, 331, 332, 333, 334, 450, 451, 452, 453, 454, 570, 571, 572, 573, 574, 690, 691, 692, 693, 694, 810, 811, 812, 813, 814, 930, 931, 932, 933, 934 },
  /* 19 */ {  95,  96,  97,  98,  99, 215, 216, 217, 218, 219, 335, 336, 337, 338, 339, 455, 456, 457, 458, 459, 575, 576, 577, 578, 579, 695, 696, 697, 698, 699, 815, 816, 817, 818, 819, 935, 936, 937, 938, 939 },
  /* 20 */ { 100, 101, 102, 103, 104, 220, 221, 222, 223, 224, 340, 341, 342, 343, 344, 460, 461, 462, 463, 464, 580, 581, 582, 583, 584, 700, 701, 702, 703, 704, 820, 821, 822, 823, 824, 940, 941, 942, 943, 944 },
  /* 21 */ { 105, 106, 107, 108, 109, 225, 226, 227, 228, 229, 345, 346, 347, 348, 349, 465, 466, 467, 468, 469, 585, 586, 587, 588, 589, 705, 706, 707, 708, 709, 825, 826, 827, 828, 829, 945, 946, 947, 948, 949 },
  /* 22 */ { 110, 111, 112, 113, 114, 230, 231, 232, 233, 234, 350, 351, 352, 353, 354, 470, 471, 472, 473, 474, 590, 591, 592, 593, 594, 710, 711, 712, 713, 714, 830, 831, 832, 833, 834, 950, 951, 952, 953, 954 },
  /* 23 */ { 115, 116, 117, 118, 119, 235, 236, 237, 238, 239, 355, 356, 357, 358, 359, 475, 476, 477, 478, 479, 595, 596, 597, 598, 599, 715, 716, 717, 718, 719, 835, 836, 837, 838, 839, 955, 956, 957, 958, 959 }

  };
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

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
  ws2812_pixel_all(0, 0, 20);

  uint16_t i;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  ws2812_pixel_all(5, 5, 5);
	  HAL_Delay(1000);
	  ws2812_pixel_all(5, 5, 0);
	  HAL_Delay(1000);

	  i = lookup_table[1][1];
	  ws2812_pixel(i, 0, 5, 5);
	  HAL_Delay(1000);
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
