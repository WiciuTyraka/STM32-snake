#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f1xx.h"
#include "lcd.h"
#include "snake.h"

UART_HandleTypeDef uart;

void send_string(char* s)
{
	HAL_UART_Transmit(&uart, (uint8_t*)s, strlen(s), 1000);
}

int main(void) {
	SystemCoreClock = 8000000; // taktowanie 8Mhz
	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOC_CLK_ENABLE()
	;
	__HAL_RCC_SPI1_CLK_ENABLE()
	;
	__HAL_RCC_USART2_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = GPIO_PIN_5 | GPIO_PIN_7;		// SCK, MOSI
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Mode = GPIO_MODE_AF_INPUT;
	gpio.Pin = GPIO_PIN_6;						// MISO
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = LCD_DC | LCD_CE | LCD_RST | LCD_BL;		//LCD SCREEN
	HAL_GPIO_Init(GPIOC, &gpio);
	HAL_GPIO_WritePin(GPIOC, LCD_CE | LCD_RST | LCD_BL, GPIO_PIN_SET);

	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = GPIO_PIN_2;              // UART TX
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Mode = GPIO_MODE_AF_INPUT;
	gpio.Pin = GPIO_PIN_3;				// UART RX
	HAL_GPIO_Init(GPIOA, &gpio);

	uart.Instance = USART2;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	uart.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart);

	spi.Instance = SPI1;
	spi.Init.Mode = SPI_MODE_MASTER;
	spi.Init.NSS = SPI_NSS_SOFT;
	spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;	// 1MHz
	spi.Init.Direction = SPI_DIRECTION_2LINES;
	spi.Init.CLKPhase = SPI_PHASE_1EDGE;
	spi.Init.CLKPolarity = SPI_POLARITY_LOW;
	spi.Init.DataSize = SPI_DATASIZE_8BIT;
	spi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	spi.Init.TIMode = SPI_TIMODE_DISABLE;
	spi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	spi.Init.CRCPolynomial = 7;
	HAL_SPI_Init(&spi);

	__HAL_SPI_ENABLE(&spi);

	snake_start();

	uint8_t factor_x = 2;
	uint8_t factor_y = 0;

	while (1) {
		if (__HAL_UART_GET_FLAG(&uart, UART_FLAG_RXNE) == SET) {
			uint8_t value;
			HAL_UART_Receive(&uart, &value, 1, 100);

			switch (value) {
			case 'a':
				send_string("w lewo \r\n");
				factor_x = -2;
				factor_y = 0;
				break;
			case 'w':
				send_string("w gore \r\n");
				factor_x = 0;
				factor_y = -2;
				break;
			case 's':
				send_string("w dol \r\n");
				factor_x = 0;
				factor_y = 2;
				break;
			case 'd':
				send_string("w prawo \r\n");
				factor_x = 2;
				factor_y = 0;
				break;
			case 'c':
				send_string("cukierek \r\n");
				candy();
				break;
			}
		}

		snake_update(factor_x, factor_y);
		HAL_Delay(100);
	}
}


