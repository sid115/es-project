#ifndef SRC_WS2812_DMA_H_
#define SRC_WS2812_DMA_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

#define WS2812_DMA_NUM_LEDS (STORAGE_SIZE + 2)

#define WS2812_DMA_HANDLE htim2
#define WS2812_DMA_BUFFER_SIZE ((WS2812_DMA_NUM_LEDS * 24) + 1)

#define WS2812_DMA_NEOPIXEL_ZERO 34
#define WS2812_DMA_NEOPIXEL_ONE 67

typedef union
{
  struct
  {
    uint8_t b;
    uint8_t r;
    uint8_t g;
  } c; // color
  uint32_t data;
} PixelRGB_t;

extern TIM_HandleTypeDef WS2812_DMA_HANDLE;
extern uint32_t ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE];
extern uint32_t* ws2812_DMA_buffer_ptr;
extern PixelRGB_t ws2812_DMA_pixels[WS2812_DMA_NUM_LEDS];

void ws2812_DMA_init(void);
void ws2812_DMA_write(PixelRGB_t* pixel);

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim),

#endif /* SRC_WS2812_DMA_H_ */
