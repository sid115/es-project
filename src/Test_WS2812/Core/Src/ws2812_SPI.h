// For a clock frequency of 84MHz, a SPI prescaler of 16 has to be used to achieve the desired frequency for WS2812
#ifndef SRC_WS2812_SPI_H_
#define SRC_WS2812_SPI_H_

#define WS2812_NUM_LEDS_X 40
#define WS2812_NUM_LEDS_Y 24

#define WS2812_NUM_LEDS (WS2812_NUM_LEDS_X * WS2812_NUM_LEDS_Y)
#define WS2812_SPI_HANDLE hspi2

#define WS2812_RESET_PULSE 60
#define WS2812_BUFFER_SIZE (WS2812_NUM_LEDS * 24 + WS2812_RESET_PULSE)

typedef struct
{
  uint8_t b;
  uint8_t r;
  uint8_t g;
} ColorRGB_t;

extern SPI_HandleTypeDef WS2812_SPI_HANDLE;
extern uint8_t ws2812_buffer[];

uint16_t coord2Index (uint8_t _x, uint8_t _y);
void ws2812_init(void);
void ws2812_pixel(uint8_t _x, uint8_t _y, ColorRGB_t* color);
void ws2812_pixel_all(ColorRGB_t* color);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef * hspi);

#endif /* SRC_WS2812_SPI_H_ */
