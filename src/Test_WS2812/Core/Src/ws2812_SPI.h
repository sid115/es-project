/*
 * ws2812_SPI.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Moritz Prenzlow
 */

// For a clock frequency of 84MHz, a SPI prescaler of 16 has to be used to achieve the desired frequency for WS2812

#ifndef SRC_WS2812_SPI_H_
#define SRC_WS2812_SPI_H_

#define WS2812_NUM_LEDS 960
#define WS2812_SPI_HANDLE hspi2

#define WS2812_RESET_PULSE 60
#define WS2812_BUFFER_SIZE (WS2812_NUM_LEDS * 24 + WS2812_RESET_PULSE)

extern SPI_HandleTypeDef WS2812_SPI_HANDLE;
extern uint8_t ws2812_buffer[];

void ws2812_init(void);
void ws2812_pixel(uint16_t led_no, uint8_t r, uint8_t g, uint8_t b);
void ws2812_pixel_all(uint8_t r, uint8_t g, uint8_t b);

#endif /* SRC_WS2812_SPI_H_ */
