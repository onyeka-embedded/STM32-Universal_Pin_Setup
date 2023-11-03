#include <stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"


static GPIO_TypeDef *getGPIO(uint8_t gpio){
	GPIO_TypeDef *port;
	
	switch(gpio)
	{
		case PORTA: 
				port = GPIOA;
				break;
		case PORTB: 
				port = GPIOB;
				break;
		case PORTC: 
				port = GPIOC;
				break;
		case PORTD: 
				port = GPIOD;
				break;
		case PORTE: 
				port = GPIOE;
				break;
		case PORTH: 
				port = GPIOH;
				break;
		default: 
				port = GPIOA;
				break;
	}
	return port;
}

static void gpio_clock_enable(uint8_t gpio_port){
	RCC->AHB1ENR |= (1 << gpio_port);
}

void pinMode(uint8_t pin, uint32_t mode){
	
	uint8_t port = pin / 16;
	uint8_t bit = pin % 16;
	GPIO_TypeDef *GPIOx = getGPIO(port);
	
	gpio_clock_enable(port); // Enable GPIOx clock
	
	GPIOx->MODER &= ~(0x03<<(bit*2)); // Reset the bits to zero (0)
	GPIOx->MODER |= (mode<<bit*2); // Set the pinMode
	
}

void digitalWrite(uint8_t port_pin, uint8_t state){
	uint8_t port = port_pin / 16;
	uint8_t pin = port_pin % 16;
	GPIO_TypeDef *GPIOx = getGPIO(port);
	
	if(state)GPIOx->ODR |= (1U<<pin); // Set pin high if state is high (1)
	else GPIOx->ODR &= ~(1U<<pin); // Set pin low if state is low (0)
	
}

uint8_t digitalRead(uint8_t pin){
	uint8_t state;
	uint8_t port = pin / 16;
	uint8_t bit = pin % 16;
	GPIO_TypeDef *GPIO = getGPIO(port);
	if(!(GPIO->IDR & (1<<bit)))state = 1;
	else state = 0;
	
	return state;
}
