#include "ws2812_SPI.h"
#include <cstdint>
#include <stdint.h>

// BEGIN INIT
uint8_t ws2812_SPI_buffer[WS2812_SPI_BUFFER_SIZE];

initLookupTable(&lookupTable, WS2812_SPI_NUM_LEDS_Y, WS2812_SPI_NUM_LEDS_X);
generateLookupTable(&lookupTable, WS2812_SPI_PANEL_WIDTH);
// END INIT

// set all pixels to 0 (off)
void ws2812_SPI_init(void)
{
  memset(ws2812_SPI_buffer, 0, WS2812_SPI_BUFFER_SIZE); // fill buffer with 0s
  HAL_SPI_Transmit_DMA(&hspi2, ws2812_SPI_buffer, WS2812_SPI_BUFFER_SIZE); // write buffer to LEDs
  ws2812_SPI_pixel_all(&(PixelRGB_t){{0, 0, 0}}); // set LEDs to black
}

// set one pixel to given color
void ws2812_SPI_pixel(uint8_t x, uint8_t y, PixelRGB_t* color)
{
  // handle out of bounds
  x = x > WS2812_SPI_NUM_LEDS_X - 1 ? WS2812_SPI_NUM_LEDS_X - 1 : x;
  y = y > WS2812_SPI_NUM_LEDS_Y - 1 ? WS2812_SPI_NUM_LEDS_Y - 1 : y;

  uint8_t* ptr = &ws2812_SPI_buffer[24 * lookupTable.index[y][x]];
  WS2812_SPI_FILL_BUFFER(color->c.g);
  WS2812_SPI_FILL_BUFFER(color->c.r);
  WS2812_SPI_FILL_BUFFER(color->c.b);
}

// set all pixels to given color
void ws2812_SPI_pixel_all(PixelRGB_t* color)
{
  uint8_t* ptr = ws2812_SPI_buffer;
  for (uint16_t i = 0; i < WS2812_SPI_NUM_LEDS; ++i) 
  {
    WS2812_SPI_FILL_BUFFER(color->c.g);
    WS2812_SPI_FILL_BUFFER(color->c.r);
    WS2812_SPI_FILL_BUFFER(color->c.b);
  }
}

// draw picture on matrix
void ws2812_SPI_draw(PixelRGB_t** picture, uint8_t width, uint8_t height)
{
  // handle out of bounds
  width = width < WS2812_SPI_NUM_LEDS_X ? width : WS2812_SPI_NUM_LEDS_X;
  height = height < WS2812_SPI_NUM_LEDS_Y ? height : WS2812_SPI_NUM_LEDS_Y;

  for (uint8_t x = 0; x < width; x++)
  {
    for (uint8_t y = 0; y < height; y++)
    {
      ws2812_SPI_pixel(x, y, &picture[y][x]);
    }
  }
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi)
{
  // restart transmission when buffer tx is completed
  HAL_SPI_Transmit_DMA(&WS2812_SPI_HANDLE, ws2812_SPI_buffer, WS2812_SPI_BUFFER_SIZE);
}
