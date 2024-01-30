/**
 * Source file implementing the functions for controlling WS2812 LEDs using SPI.
 *
 * This file includes the implementation of the functions defined in ws2812_SPI.h for interfacing
 * with WS2812 LED strips via an SPI peripheral. It handles the initialization of the LED strip,
 * setting individual or all LED colors, and drawing pictures or patterns on the LED matrix. The
 * implementation converts RGB color data into a format suitable for WS2812 LEDs and transmits this
 * data using SPI.
 *
 * The SPI communication is configured to match the timing requirements of WS2812 LEDs, and the
 * buffer is used to store the SPI data for transmission. The functions in this file abstract the
 * complexity of interfacing with the LED strip, providing simple interfaces for various LED control
 * operations.
 *
 * The file also includes the initialization of the lookup table for LED coordinates, using data
 * from lookup_table.h, to facilitate addressing LEDs in a grid layout.
 */

#include "ws2812_SPI.h"
#include <cstdint>
#include <stdint.h>

/* BEGIN INIT */
/* Global buffer for SPI data transmission */
uint8_t ws2812_SPI_buffer[WS2812_SPI_BUFFER_SIZE];

/* Initialize lookup table for LED grid */
initLookupTable(&lookupTable, WS2812_SPI_NUM_LEDS_Y, WS2812_SPI_NUM_LEDS_X);
generateLookupTable(&lookupTable, WS2812_SPI_PANEL_WIDTH);
/* END INIT */

/**
 * Initializes the WS2812 LED strip for use.
 *
 * This function clears the SPI buffer and sets all LEDs to an initial 'off' state (black). It is
 * necessary to call this function before performing any operations on the LED strip to ensure the
 * strip is in a known state and ready for data transmission.
 */
void ws2812_SPI_init(void)
{
  memset(ws2812_SPI_buffer, 0, WS2812_SPI_BUFFER_SIZE); /* fill buffer with 0s */
  HAL_SPI_Transmit_DMA(&hspi2, ws2812_SPI_buffer, WS2812_SPI_BUFFER_SIZE); /* write buffer to LEDs */
  ws2812_SPI_pixel_all(&(PixelRGB_t){{0, 0, 0}}); /* set LEDs to black */
}

/**
 * Sets the color of an individual pixel on the LED matrix.
 *
 * Parameters:
 *   x: The x-coordinate of the pixel to set.
 *   y: The y-coordinate of the pixel to set.
 *   color: A pointer to the PixelRGB_t structure containing the color to set the pixel.
 *
 * Description:
 *   This function sets the specified pixel to the provided color. It handles out-of-bounds
 *   coordinates and updates the SPI buffer with the new color data for the specified pixel.
 */
void ws2812_SPI_pixel(uint8_t x, uint8_t y, PixelRGB_t* color)
{
  /* handle out of bounds */
  x = x > WS2812_SPI_NUM_LEDS_X - 1 ? WS2812_SPI_NUM_LEDS_X - 1 : x;
  y = y > WS2812_SPI_NUM_LEDS_Y - 1 ? WS2812_SPI_NUM_LEDS_Y - 1 : y;

  uint8_t* ptr = &ws2812_SPI_buffer[24 * lookupTable.index[y][x]];
  WS2812_SPI_FILL_BUFFER(color->c.g);
  WS2812_SPI_FILL_BUFFER(color->c.r);
  WS2812_SPI_FILL_BUFFER(color->c.b);
}

/**
 * Sets all pixels on the LED matrix to the same specified color.
 *
 * Parameters:
 *   color: A pointer to the PixelRGB_t structure containing the color to set all pixels.
 *
 * Description:
 *   This function sets the entire LED matrix to a single color. It updates the SPI buffer with the
 *   color data for each LED, effectively filling the entire matrix with the specified color.
 */
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

/**
 * Renders a picture or pattern on the LED matrix.
 *
 * Parameters:
 *   picture: A 2D array of PixelRGB_t structures representing the picture to draw.
 *   width: The width of the picture.
 *   height: The height of the picture.
 *
 * Description:
 *   This function draws the provided picture on the LED matrix. It handles out-of-bounds dimensions
 *   and sets each pixel in the matrix to the corresponding color in the picture array.
 */
void ws2812_SPI_draw(PixelRGB_t** picture, uint8_t width, uint8_t height)
{
  /* handle out of bounds */
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

/**
 * Callback function for SPI transmission completion.
 *
 * Parameters:
 *   hspi: A pointer to the SPI_HandleTypeDef structure that provides information about the SPI 
 *         communication and the state of the SPI peripheral.
 *
 * Description:
 *   This function is called when an SPI transmission is completed. It is used to restart the
 *   transmission of the SPI buffer to continuously update the LED matrix with new data.
 */
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi)
{
  /* restart transmission when buffer tx is completed */
  HAL_SPI_Transmit_DMA(&WS2812_SPI_HANDLE, ws2812_SPI_buffer, WS2812_SPI_BUFFER_SIZE);
}
