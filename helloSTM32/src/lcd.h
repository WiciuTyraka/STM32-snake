#ifndef __LCD__
#define __LCD__

#include <stdint.h>
#include "stm32f1xx.h"

#define LCD_WIDTH				84
#define LCD_HEIGHT				48

#define LCD_DC			GPIO_PIN_1
#define LCD_CE			GPIO_PIN_2
#define LCD_RST			GPIO_PIN_3
#define LCD_BL			GPIO_PIN_0

extern SPI_HandleTypeDef spi;

void lcd_setup(void);

void lcd_clear(void);
void lcd_draw_bitmap(const uint8_t* data);
void lcd_draw_pixel(int x, int y);
void lcd_draw_text(int row, int col, const char* text);
void lcd_draw_line(int x1, int y1, int x2, int y2);

void lcd_copy(void);

#endif // __LCD__
