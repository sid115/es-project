/**
 * Source file implementing the functions for controlling WS2812 LEDs using DMA and a timer.
 *
 * This file includes the implementation of the functions defined in ws2812_DMA.h for interfacing
 * with WS2812 LED strips using DMA (Direct Memory Access) in conjunction with a timer peripheral.
 * It handles the conversion of RGB color data into a format suitable for WS2812 LEDs and transmits
 * this data using DMA for efficient and non-blocking LED updates.
 *
 * The file defines global variables for the DMA buffer and the LED pixel data and includes functions
 * for initializing the DMA settings, writing color data to the LEDs, and handling relevant timer
 * callbacks.
 */

#include "ws2812_DMA.h"

/* BEGIN INIT */
uint32_t ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE];
uint32_t* ws2812_DMA_buffer_ptr;
PixelRGB_t ws2812_DMA_pixels[WS2812_DMA_NUM_LEDS];
/* END INIT */


/**
 * Initializes the DMA and timer settings for WS2812 LED control.
 *
 * This function clears the SPI buffer and sets all LEDs to an initial 'off' state (black). It is
 * necessary to call this function before performing any operations on the LED strip to ensure the
 * strip is in a known state and ready for data transmission.
 */
void ws2812_DMA_init(void)
{
    /* initialize the DMA buffer */
    ws2812_DMA_buffer_ptr = ws2812_DMA_buffer;
    for (uint8_t i = 0; i < WS2812_DMA_BUFFER_SIZE; i++)
    {
        ws2812_DMA_buffer[i] = 0;
    }
}

/**
 * Writes color data for all LEDs to the DMA buffer.
 *
 * Parameters:
 *   pixel: A pointer to an array of PixelRGB_t structures containing the color data for each LED.
 *
 * Description:
 *   This function populates the DMA buffer with color data formatted for WS2812 LEDs. It converts
 *   the RGB color values for each LED into a series of high and low pulses corresponding to the
 *   WS2812 protocol. The function then initiates DMA-based PWM transmission to update the LEDs.
 */
void ws2812_DMA_write(PixelRGB_t* pixel)
{
  uint8_t i, j; /* loop counters */
  
  ws2812_DMA_buffer_ptr = ws2812_DMA_buffer;
  for (i = 0; i < WS2812_DMA_NUM_LEDS; i++)
  {
    for (j = 23; j >= 0; j--)
     {
       /* write a 1 or 0 to the DMA buffer */
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
  ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE - 1] = 0; /* last element must be 0! */
 
  /* start the DMA transfer */
  HAL_TIM_PWM_Start_DMA(&WS2812_DMA_HANDLE, TIM_CHANNEL_3, ws2812_DMA_buffer, WS2812_DMA_BUFFER_SIZE);
}

/**
 * Callback function for PWM pulse completion in DMA mode.
 *
 * Parameters:
 *   htim: A pointer to the TIM_HandleTypeDef structure that provides information about the
 *         timer and the state of the timer peripheral.
 *
 * Description:
 *   This function is called when a PWM pulse is completed in DMA mode. It is used to stop
 *   the DMA transmission, marking the completion of one cycle of LED updates.
 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_3);
}

/**
 * Callback function for timer period elapse.
 *
 * Parameters:
 *   htim: A pointer to the TIM_HandleTypeDef structure that provides information about the
 *         timer and the state of the timer peripheral.
 *
 * Description:
 *   This function is called when the timer period elapses. It is used to handle timer-related
 *   interrupts and can be used to trigger LED updates or other time-sensitive operations.
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* check which timer triggered this callback */
  if(htim->Instance == TIM3)
  {
    /* set the timer IRQ flag */
    timer_irq = true;
  }
}
