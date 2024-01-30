/**
 * Header file for controlling WS2812 LEDs using SPI (Serial Peripheral Interface).
 *
 * This file provides definitions and function prototypes for interfacing with WS2812 LEDs using
 * an SPI communication protocol. It includes constants and structures to facilitate the control of
 * WS2812 LED panels, as well as functions to initialize the LEDs, set individual pixel colors, and
 * render images or color patterns on the LED panels.
 *
 * The implementation is designed for a specific clock frequency and utilizes SPI to simulate the 
 * timing-specific one-wire protocol of the WS2812 LEDs. The SPI prescaler and other settings are 
 * tailored to match the timing requirements of the WS2812 LED communication.
 *
 * Constants:
 *   - WS2812_SPI_*: Various constants define the dimensions of the LED panels, the number of panels,
 *                   the number of LEDs, and buffer sizes for SPI communication.
 *
 *   - WS2812_SPI_FILL_BUFFER: A macro to fill the SPI buffer with color data formatted for WS2812 LEDs.
 *
 * Types:
 *   - PixelRGB_t: A union representing an RGB pixel with individual 8-bit color components or a single
 *                 32-bit value for convenient color manipulation.
 *
 * Global Variables:
 *   - WS2812_SPI_HANDLE: An SPI_HandleTypeDef structure used for SPI communication.
 *   - ws2812_SPI_buffer: An array used as a buffer for SPI data transmission.
 *
 * Functions:
 *   - ws2812_SPI_init: Initializes the SPI peripheral and the ws2812_SPI_buffer for WS2812 LED control.
 *   - ws2812_SPI_pixel: Sets the color of an individual pixel at specified coordinates.
 *   - ws2812_SPI_pixel_all: Sets all pixels to the same specified color.
 *   - ws2812_SPI_draw: Renders a given picture or pattern to the LED panels.
 *   - HAL_SPI_TxCpltCallback: SPI transmission complete callback function.
 *
 * This header is part of a larger project that includes other components such as a lookup table for
 * LED coordinates and a main controller. It is essential for the SPI settings and the microcontroller
 * hardware to be compatible with the timing requirements of the WS2812 LEDs.
 */

#ifndef SRC_WS2812_SPI_H_
#define SRC_WS2812_SPI_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "lookup_table.h"
#include "main.h"

#define WS2812_SPI_PANEL_WIDTH 8
#define WS2812_SPI_NUM_PANELS_X 5
#define WS2812_SPI_NUM_PANELS_Y 3

#define WS2812_SPI_NUM_LEDS_X (WS2812_SPI_PANEL_WIDTH * WS2812_SPI_NUM_PANELS_X)
#define WS2812_SPI_NUM_LEDS_Y (WS2812_SPI_PANEL_WIDTH * WS2812_SPI_NUM_PANELS_Y)
#define WS2812_SPI_NUM_LEDS (WS2812_SPI_NUM_LEDS_X * WS2812_SPI_NUM_LEDS_Y)

#define WS2812_SPI_HANDLE hspi2
#define WS2812_SPI_RESET_PULSE 60
#define WS2812_SPI_BUFFER_SIZE (WS2812_SPI_NUM_LEDS * 24 + WS2812_SPI_RESET_PULSE)

#define WS2812_SPI_FILL_BUFFER(COLOR) \
  for (uint8_t mask = 0x80; mask; mask >>= 1) \
  { \
    if (COLOR & mask) \
    { \
      *ptr++ = 0xfc; \
    } \
    else \
    { \
      *ptr++ = 0x80; \
    } \
  }

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
extern SPI_HandleTypeDef WS2812_SPI_HANDLE;
extern uint8_t ws2812_SPI_buffer[];

/* Function prototypes */
void ws2812_SPI_init(void);
void ws2812_SPI_pixel(uint8_t x, uint8_t y, PixelRGB_t* color);
void ws2812_SPI_pixel_all(PixelRGB_t* color);
void ws2812_SPI_draw(PixelRGB_t** picture, uint8_t width, uint8_t height);

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi);

#endif /* SRC_WS2812_SPI_H_ */
