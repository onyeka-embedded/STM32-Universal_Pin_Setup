#ifndef _GPIO_H_
#define _GPIO_H_
#include <stdint.h>
#include "stm32f4xx.h"


/**** Mapping GPIO to positions in RCC_AHB1ENR register *****/
#define PORTA          0           
#define PORTB          1           
#define PORTC          2  
#define PORTD          3 
#define PORTE          4 
#define PORTH          7 


#define INPUT 		0
#define OUTPUT 		1
#define ALT_FUNC	2
#define ANALOG 		3


#define HIGH  1
#define LOW 	0

/**** Enums for the PORT pins *****/
enum PA{PA0=0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15}; 
enum PB{PB0=16,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,PB14,PB15}; 
enum PC{PC0=32,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PC8,PC9,PC10,PC11,PC12,PC13,PC14,PC15}; 
enum PD{PD0=48,PD1,PD2,PD3,PD4,PD5,PD6,PD7,PD8,PD9,PD10,PD11,PD12,PD13,PD14,PD15}; 
enum PE{PE0=64,PE1,PE2,PE3,PE4,PE5,PE6,PE7,PE8,PE9,PE10,PE11,PE12,PE13,PE14,PE15};  
enum PH{PH0=112,PH1,PH2,PH3,PH4,PH5,PH6,PH7,PH8,PH9,PH10,PH11,PH12,PH13,PH14,PH15}; 



void pinMode(uint8_t port_pin, uint32_t mode);
void digitalWrite(uint8_t port_pin, uint8_t state);
uint8_t digitalRead(uint8_t port_pin);

#endif
