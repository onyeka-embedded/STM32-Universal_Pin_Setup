#include "stm32f4xx.h"
#include "gpio.h"
#include "delay.h"

#define LEDpin PA5

void myDelay(int loopDelay);

int main(void){
	pinMode(LEDpin, OUTPUT);
	//pinMode(PC13, INPUT);
	
	while(1){
		//if(digitalRead(PC13) == 1)digitalWrite(LEDpin, HIGH);
	//else {digitalWrite(LEDpin, LOW);}
	digitalWrite(LEDpin, LOW);
	myDelay(500000);
	digitalWrite(LEDpin, HIGH);
	myDelay(500000);
	}
}
