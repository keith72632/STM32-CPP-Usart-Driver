/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include "led.h"
#include "usart.h"
#include "main.h"


void delay()
{
	for(size_t i = 0; i < 1000000; i++){};
}

int main(void)
{
	//enable gpio a clock

	rcc_clk_t rcc_pin = GPIOD;
	pin_t pin15 = PIN_15;

	usart usart2(USART2_CLK, GPIOA_CLK, GPIOA_MODE, USART2_BASE);
	usart2.usart_init();


    /* Loop forever */
	led pin_d(GPIOD_CLK, GPIOD_MODE, GPIOD_ODR, rcc_pin, pin15);
	pin_d.start_clock();

	while(1)
	{
		usart2.uputc('X');
		pin_d.led_on();
		delay();
		pin_d.led_off();
		delay();
	}
}
