#include <stdint.h>
#include <stdio.h>
#include "main.h"

uint32_t volatile *const RCC_AHB1ENR = (uint32_t*)(0x40023800 + 0x30);
uint32_t volatile *const GPIOA_MODER = (uint32_t*)(0x40020000 + 0x00);
uint32_t volatile *const GPIOA_PUPDR = (uint32_t*)(0x40020000 + 0x0C);
uint32_t volatile *const GPIOA_IDR = (uint32_t*)(0x40020000 + 0x10);
uint32_t volatile *const GPIOA_ODR = (uint32_t*)(0x40020000 + 0x14);

void read_keypad(char char1, char char2, char char3, char char4);
void set_pins_1(void);
void delay(void);

int main(void) {

	*RCC_AHB1ENR |= 1;
	*GPIOA_MODER &= ~(0xF); // set from PA0 to PA1 as input
	*GPIOA_MODER &= ~(0xF << 16); // set from PA8 to PA9 as input
	*GPIOA_MODER |= (0x55 << 8); // starting set from PA4 to PA7 as output
	*GPIOA_MODER &= ~(0xAA << 8); // ending set from PA4 to PA7 as output
	*GPIOA_PUPDR |= (0x5 << 0); // starting enabling from PA0 to PA1 pull-up resistor
	*GPIOA_PUPDR &= ~(0xA << 0); // ending enabling from PA0 to PA1 pull-up resistor
	*GPIOA_PUPDR |= (0x5 << 16); // starting enabling from PA8 to PA9 pull-up resistor
	*GPIOA_PUPDR &= ~(0xA << 16); // ending enabling from PA8 to PA9 pull-up resistor


	while(1) {
		set_pins_1();
		*GPIOA_ODR &= ~(1 << 4);
		read_keypad('1', '2', '3', 'A');

		set_pins_1();
		*GPIOA_ODR &= ~(1 << 5);
		read_keypad('4', '5', '6', 'B');

		set_pins_1();
		*GPIOA_ODR &= ~(1 << 6);
		read_keypad('7', '8', '9', 'C');

		set_pins_1();
		*GPIOA_ODR &= ~(1 << 7);
		read_keypad('*', '0', '#', 'D');
	}
}

void read_keypad(char char1, char char2, char char3, char char4) {
	if(!(((*GPIOA_IDR >> 0) & 1) | 0)) {
		delay();
		printf(" %c\n", char1);
		set_pins_1();
	} else if(!(((*GPIOA_IDR >> 1) & 1) | 0)) {
		delay();
		printf(" %c\n", char2);
		set_pins_1();
	} else if(!(((*GPIOA_IDR >> 8) & 1) | 0)) {
		delay();
		printf(" %c\n", char3);
		set_pins_1();
	} else if(!(((*GPIOA_IDR >> 9) & 1) | 0)) {
		delay();
		printf(" %c\n", char4);
		set_pins_1();
	}
}

void set_pins_1(void) {
	*GPIOA_ODR |= 0xF << 4;
}

void delay(void) {
	for(uint32_t volatile i = 0; i < 350000; i++);
}
