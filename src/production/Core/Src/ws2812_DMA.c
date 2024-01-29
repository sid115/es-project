#include "ws2812_DMA.h"

// BEGIN INIT
uint32_t ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE];
uint32_t* ws2812_DMA_buffer_ptr;
PixelRGB_t ws2812_DMA_pixels[WS2812_DMA_NUM_LEDS];
// END INIT

// set all pixels to 0 (off)
void ws2812_DMA_init(void)
{
}

void ws2812_DMA_write(PixelRGB_t* pixel)
{
  uint8_t i, j;
  
  ws2812_DMA_buffer_ptr = ws2812_DMA_buffer;
  for (i = 0; i < WS2812_DMA_NUM_LEDS; i++)
  {
    for (j = 23; j >= 0; j--)
     {
       if ((pixel[i].data >> j) & 0x01)
       {
         *ws2812_DMA_buffer_ptr = WS2812_DMA_NEOPIXEL_ONE; 
       }
       else
       {
         *ws2812_DMA_buffer_ptr = WS2812_DMA_NEOPIXEL_ZERO;
       }
       ws2812_DMA_buffer_ptr++;
    }
  }
  ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE - 1] = 0; // last element must be 0!
 
  HAL_TIM_PWM_Start_DMA(&WS2812_DMA_HANDLE, TIM_CHANNEL_3, ws2812_DMA_buffer, WS2812_DMA_BUFFER_SIZE);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_3);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM3)
  {
    timer_irq = true;
  }
}
