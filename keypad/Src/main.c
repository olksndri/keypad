#include <stdint.h>
#include <stdio.h>
#include "main.h"

RCC_AHB1ENR_t volatile *const RCC_AHB1ENR = (RCC_AHB1ENR_t*)(0x40023800 + 0x30);
GPIOx_MODER_t volatile *const GPIOA_MODER = (GPIOx_MODER_t*)(0x40020000 + 0x00);
GPIOx_PUPDR_t volatile *const GPIOA_PUPDR = (GPIOx_PUPDR_t*)(0x40020000 + 0x0C);
GPIOx_IDR_t volatile *const GPIOA_IDR = (GPIOx_IDR_t*)(0x40020000 + 0x10);
GPIOx_ODR_t volatile *const GPIOA_ODR = (GPIOx_ODR_t*)(0x40020000 + 0x14);

void read_keypad(char char1, char char2, char char3, char char4);
void set_pins_1(void);
void delay(void);

int main(void) {
	RCC_AHB1ENR->GPIOA_EN |= 1;
	GPIOA_MODER->MODER0 &= 0;
	GPIOA_MODER->MODER1 &= 0;
	GPIOA_MODER->MODER8 &= 0;
	GPIOA_MODER->MODER9 &= 0;
	GPIOA_MODER->MODER4 |= 1;
	GPIOA_MODER->MODER5 |= 1;
	GPIOA_MODER->MODER6 |= 1;
	GPIOA_MODER->MODER7 |= 1;
	GPIOA_PUPDR->PUPDR0 |= 1;
	GPIOA_PUPDR->PUPDR1 |= 1;
	GPIOA_PUPDR->PUPDR8 |= 1;
	GPIOA_PUPDR->PUPDR9 |= 1;

	while(1) {
		set_pins_1();
		GPIOA_ODR->ODR4 &= 0;
		read_keypad('1', '2', '3', 'A');

		set_pins_1();
		GPIOA_ODR->ODR5 &= 0;
		read_keypad('4', '5', '6', 'B');

		set_pins_1();
		GPIOA_ODR->ODR6 &= 0;
		read_keypad('7', '8', '9', 'C');

		set_pins_1();
		GPIOA_ODR->ODR7 &= 0;
		read_keypad('*', '0', '#', 'D');
	}
}

void read_keypad(char char1, char char2, char char3, char char4) {
	if(!(GPIOA_IDR->IDR0)) {
		printf(" %c\n", char1);
		delay();
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR1)) {
		printf(" %c\n", char2);
		delay();
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR8)) {
		printf(" %c\n", char3);
		delay();
		set_pins_1();
	} else if(!(GPIOA_IDR->IDR9)) {
		printf(" %c\n", char4);
		delay();
		set_pins_1();
	}
}

void set_pins_1(void) {
	GPIOA_ODR->ODR4 |= 1;
	GPIOA_ODR->ODR5 |= 1;
	GPIOA_ODR->ODR6 |= 1;
	GPIOA_ODR->ODR7 |= 1;
}

void delay(void) {
	for(uint32_t volatile i = 0; i < 571428; i++);
	/* each iteration of the loop =
	 execution of 7 processor assembly instructions:

	1 ldr     r3, [r7, #4]
	2 adds    r3, #1
	3 str     r3, [r7, #4]
	4 ldr     r3, [r7, #4]
	5 ldr     r2, [pc, #16]   ; (0x8000580 <delay+40>)
	6 cmp     r3, r2
	7 bls.n   0x8000564 <delay+12>

	processor running with frequency 16MHz of internal RC oscillator (by default)

	-> time for 6 instructions to be executed = 7 / 16 (10^6) = 4,375 * (10^-7)
	-> number of loop iterations for 1 second delay = 2 285 714 (iter's)
	-> number of loop iterations for 0.5 second delay = 1 142 857 (iter's)
	-> number of loop iterations for 0.250 second delay = 571 428 (iter's)

	 */
}

