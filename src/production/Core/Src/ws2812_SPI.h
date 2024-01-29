// For a clock frequency of 84MHz, a SPI prescaler of 16 has to be used to achieve the desired frequency for WS2812
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

extern SPI_HandleTypeDef WS2812_SPI_HANDLE;
extern uint8_t ws2812_SPI_buffer[];

void ws2812_SPI_init(void);
void ws2812_SPI_pixel(uint8_t x, uint8_t y, PixelRGB_t* color);
void ws2812_SPI_pixel_all(PixelRGB_t* color);
void ws2812_SPI_draw(PixelRGB_t** picture, uint8_t width, uint8_t height);

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi);

#endif /* SRC_WS2812_SPI_H_ */
