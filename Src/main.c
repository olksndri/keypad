#include <stdint.h>
#include <stdio.h>
#include "main.h"

RCC_AHB1ENR_t volatile *const RCC_AHB1ENR 	= ADDR_RCC_AHB1ENR;
GPIOx_MODER_t volatile *const GPIOA_MODER 	= ADDR_GPIOA_MODER;
GPIOx_PUPDR_t volatile *const GPIOA_PUPDR 	= ADDR_GPIOA_PUPDR;
GPIOx_IDR_t volatile *const GPIOA_IDR 		= ADDR_GPIOA_IDR;
GPIOx_ODR_t volatile *const GPIOA_ODR 		= ADDR_GPIOA_ODR;

void read_keypad(char char1, char char2, char char3, char char4);
void set_pins_1(void);
void delay(void);

int main(void) {
	RCC_AHB1ENR->GPIOA_EN 	= GPIOx_ENABLE;
	GPIOA_MODER->MODER0 	= GPIOx_INPUT_MODE;
	GPIOA_MODER->MODER1 	= GPIOx_INPUT_MODE;
	GPIOA_MODER->MODER8 	= GPIOx_INPUT_MODE;
	GPIOA_MODER->MODER9 	= GPIOx_INPUT_MODE;
	GPIOA_MODER->MODER4 	= GPIOx_OUTPUT_MODE;
	GPIOA_MODER->MODER5     = GPIOx_OUTPUT_MODE;
	GPIOA_MODER->MODER6     = GPIOx_OUTPUT_MODE;
	GPIOA_MODER->MODER7     = GPIOx_OUTPUT_MODE;
	GPIOA_PUPDR->PUPDR0     = GPIOx_PULL_UP;
	GPIOA_PUPDR->PUPDR1     = GPIOx_PULL_UP;
	GPIOA_PUPDR->PUPDR8     = GPIOx_PULL_UP;
	GPIOA_PUPDR->PUPDR9     = GPIOx_PULL_UP;

	while(1) {
		set_pins_1();
		GPIOA_ODR->ODR4 = PIN_LOW;
		read_keypad('1', '2', '3', 'A');

		set_pins_1();
		GPIOA_ODR->ODR5 = PIN_LOW;
		read_keypad('4', '5', '6', 'B');

		set_pins_1();
		GPIOA_ODR->ODR6 = PIN_LOW;
		read_keypad('7', '8', '9', 'C');

		set_pins_1();
		GPIOA_ODR->ODR7 = PIN_LOW;
		read_keypad('*', '0', '#', 'D');
	}
}

void read_keypad(char char1, char char2, char char3, char char4) {
	if(!(GPIOA_IDR->IDR0)) {
		delay();
		printf(" %c\n", char1);
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR1)) {
		delay();
		printf(" %c\n", char2);
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR8)) {
		delay();
		printf(" %c\n", char3);
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR9)) {
		delay();
		printf(" %c\n", char4);
		set_pins_1();
	}
}

void set_pins_1(void) {
	GPIOA_ODR->ODR4 = PIN_HIGH;
	GPIOA_ODR->ODR5 = PIN_HIGH;
	GPIOA_ODR->ODR6 = PIN_HIGH;
	GPIOA_ODR->ODR7 = PIN_HIGH;
}

void delay(void) {
	for(uint32_t volatile i = 0; i < DELAY_250ms; i++);
}

