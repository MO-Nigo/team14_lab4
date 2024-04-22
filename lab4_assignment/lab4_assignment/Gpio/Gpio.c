/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
		uint8 DefaultState) {
	switch (PortName) {
	case GPIO_A:
		GPIOA_MODER &= ~(0x03 << (PinNum * 2));
		GPIOA_MODER |= (PinMode << (PinNum * 2));

		GPIOA_OTYPER &= ~(0x01 << PinNum);
		GPIOA_OTYPER |= (DefaultState << PinNum);

		break;
	case GPIO_B:
	   
	
		GPIOB_MODER &= ~(0x03 << (PinNum * 2));
		GPIOB_MODER |= (PinMode << (PinNum * 2));

		GPIOB_OTYPER &= ~(0x01 << PinNum);
		GPIOB_OTYPER |= (DefaultState << PinNum);
		break;
	case GPIO_C:
	    GPIOC_MODER &= ~(0x03 << (PinNum * 2));
		GPIOC_MODER |= (PinMode << (PinNum * 2));

		GPIOC_OTYPER &= ~(0x01 << PinNum);
		GPIOC_OTYPER |= (DefaultState << PinNum);
		
		break;
	case GPIO_D:
	    GPIOD_MODER &= ~(0x03 << (PinNum * 2));
		GPIOD_MODER |= (PinMode << (PinNum * 2));

		GPIOD_OTYPER &= ~(0x01 << PinNum);
		GPIOD_OTYPER |= (DefaultState << PinNum);
		
		break;
	default:
		break;
	}
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

	uint8 check = (GPIOA_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
	if (check == 0x01) {

		switch (PortName) {
		case GPIO_A:
			GPIOA_ODR &= ~(0x1 << PinNum);
			GPIOA_ODR |= (Data << PinNum);
			break;
		case GPIO_B:
			GPIOB_ODR &= ~(0x1 << PinNum);
			GPIOB_ODR |= (Data << PinNum);
			break;
		case GPIO_C:
			GPIOC_ODR &= ~(0x1 << PinNum);
			GPIOC_ODR |= (Data << PinNum);
			break;
		case GPIO_D:
			GPIOD_ODR &= ~(0x1 << PinNum);
			GPIOD_ODR |= (Data << PinNum);
			break;
		default:
			break;
		}
	return OK;
	}
	else {
		return NOK ;
	}

}
