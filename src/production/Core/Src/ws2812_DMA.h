/**
 * Header file for controlling WS2812 LEDs using DMA (Direct Memory Access) and a timer peripheral.
 *
 * This file provides definitions and function prototypes for interfacing with WS2812 LEDs using
 * DMA in conjunction with a timer peripheral to generate the necessary waveforms for controlling
 * the LEDs. It includes constants and structures to facilitate the control of WS2812 LED strips,
 * as well as functions to initialize the DMA and timer settings and to write color data to the LEDs.
 *
 * The implementation is specifically designed to match the timing requirements of WS2812 LEDs
 * using a DMA buffer, which allows for efficient and non-blocking updates to the LED strip. The DMA
 * buffer is filled with timing-specific values that correspond to the color data for each LED.
 *
 * Constants:
 *   - WS2812_DMA_*: Various constants define the number of LEDs, buffer sizes, and specific values
 *                   representing logical '0' and '1' for the WS2812 LEDs.
 *
 * Types:
 *   - PixelRGB_t: A union representing an RGB pixel with individual 8-bit color components or a single
 *                 32-bit value for convenient color manipulation and alignment.
 *
 * Global Variables:
 *   - WS2812_DMA_HANDLE: A TIM_HandleTypeDef structure used for timer-based DMA communication.
 *   - ws2812_DMA_buffer: An array used as a buffer for DMA data transmission.
 *   - ws2812_DMA_buffer_ptr: A pointer to the DMA buffer, used in DMA operations.
 *   - ws2812_DMA_pixels: An array of PixelRGB_t structures representing the color data for each LED.
 *
 * Functions:
 *   - ws2812_DMA_init: Initializes the DMA and timer settings for WS2812 LED control.
 *   - ws2812_DMA_write: Writes color data for a single pixel to the DMA buffer.
 *   - HAL_TIM_PWM_PulseFinishedCallback: Callback function for PWM pulse completion.
 *   - HAL_TIM_PeriodElapsedCallback: Callback function for timer period elapse.
 *
 * This header is part of a larger project that includes other components and is tailored for
 * systems where non-blocking LED updates are crucial. It requires specific hardware capabilities
 * and careful configuration of the timer and DMA settings to match the WS2812 communication protocol.
 */

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

/* Pixel structure */
typedef union
{
  struct
  {
    uint8_t b; /* blue */
    uint8_t r; /* red */
    uint8_t g; /* green */
  } c; /* color */
  uint32_t data; /* 32-bit for alignment */
} PixelRGB_t;

/* Global variables */
extern TIM_HandleTypeDef WS2812_DMA_HANDLE;
extern uint32_t ws2812_DMA_buffer[WS2812_DMA_BUFFER_SIZE];
extern uint32_t* ws2812_DMA_buffer_ptr;
extern PixelRGB_t ws2812_DMA_pixels[WS2812_DMA_NUM_LEDS];

/* Function prototypes */
void ws2812_DMA_init(void);
void ws2812_DMA_write(PixelRGB_t* pixel);

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* SRC_WS2812_DMA_H_ */
