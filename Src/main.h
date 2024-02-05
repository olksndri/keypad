#ifndef MAIN_H_
#define MAIN_H_

#define ADDR_RCC_AHB1ENR 	((RCC_AHB1ENR_t*)(0x40023800 + 0x30))
#define ADDR_GPIOA_MODER 	((GPIOx_MODER_t*)(0x40020000 + 0x00))
#define ADDR_GPIOA_PUPDR 	((GPIOx_PUPDR_t*)(0x40020000 + 0x0C))
#define ADDR_GPIOA_IDR 		((GPIOx_IDR_t*)(0x40020000 + 0x10))
#define ADDR_GPIOA_ODR 		((GPIOx_ODR_t*)(0x40020000 + 0x14))

#define GPIOx_ENABLE 		(1)
#define GPIOx_DISABLE 		(0)
#define	GPIOx_INPUT_MODE 	(0)
#define	GPIOx_OUTPUT_MODE 	(1)
#define GPIOx_FUNCTION_MODE (2)
#define GPIOx_ANALOG_MODE 	(3)
#define GPIOx_PULL_UP 		(1)
#define GPIOx_PULL_DOWN 	(2)
#define PIN_HIGH			(1)
#define PIN_LOW 			(0)

#define DELAY_250ms 	(571428ul)
#define DELAY_500ms 	(1142857ul)
#define DELAY_1000ms 	(2285714ul)

typedef struct {
	uint32_t GPIOA_EN:1;
	uint32_t GPIOB_EN:1;
	uint32_t GPIOC_EN:1;
	uint32_t GPIOD_EN:1;
	uint32_t GPIOE_EN:1;
	uint32_t RESERVED_1:2;
	uint32_t GPIOH_EN:1;
	uint32_t RESERVED_2:4;
	uint32_t CRC_EN:1;
	uint32_t RESERVED_3:8;
	uint32_t DMA1_EN:1;
	uint32_t DMA2_EN:1;
	uint32_t RESERVED_4:9;
}RCC_AHB1ENR_t;

typedef struct {
	uint32_t MODER0:2;
	uint32_t MODER1:2;
	uint32_t MODER2:2;
	uint32_t MODER3:2;
	uint32_t MODER4:2;
	uint32_t MODER5:2;
	uint32_t MODER6:2;
	uint32_t MODER7:2;
	uint32_t MODER8:2;
	uint32_t MODER9:2;
	uint32_t MODER10:2;
	uint32_t MODER11:2;
	uint32_t MODER12:2;
	uint32_t MODER13:2;
	uint32_t MODER14:2;
	uint32_t MODER15:2;
}GPIOx_MODER_t;

typedef struct {
	uint32_t PUPDR0:2;
	uint32_t PUPDR1:2;
	uint32_t PUPDR2:2;
	uint32_t PUPDR3:2;
	uint32_t PUPDR4:2;
	uint32_t PUPDR5:2;
	uint32_t PUPDR6:2;
	uint32_t PUPDR7:2;
	uint32_t PUPDR8:2;
	uint32_t PUPDR9:2;
	uint32_t PUPDR10:2;
	uint32_t PUPDR11:2;
	uint32_t PUPDR12:2;
	uint32_t PUPDR13:2;
	uint32_t PUPDR14:2;
	uint32_t PUPDR15:2;
}GPIOx_PUPDR_t;

typedef struct {
	uint32_t IDR0:1;
	uint32_t IDR1:1;
	uint32_t IDR2:1;
	uint32_t IDR3:1;
	uint32_t IDR4:1;
	uint32_t IDR5:1;
	uint32_t IDR6:1;
	uint32_t IDR7:1;
	uint32_t IDR8:1;
	uint32_t IDR9:1;
	uint32_t IDR10:1;
	uint32_t IDR11:1;
	uint32_t IDR12:1;
	uint32_t IDR13:1;
	uint32_t IDR14:1;
	uint32_t IDR15:1;
	uint32_t RESERVED:16;
}GPIOx_IDR_t;


typedef struct {
	uint32_t ODR0:1;
	uint32_t ODR1:1;
	uint32_t ODR2:1;
	uint32_t ODR3:1;
	uint32_t ODR4:1;
	uint32_t ODR5:1;
	uint32_t ODR6:1;
	uint32_t ODR7:1;
	uint32_t ODR8:1;
	uint32_t ODR9:1;
	uint32_t ODR10:1;
	uint32_t ODR11:1;
	uint32_t ODR12:1;
	uint32_t ODR13:1;
	uint32_t ODR14:1;
	uint32_t ODR15:1;
	uint32_t RESERVED:16;
}GPIOx_ODR_t;


#endif
