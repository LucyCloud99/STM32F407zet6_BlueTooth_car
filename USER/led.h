#ifndef __LED_H__
#define __LED_H__
		
#include "stm32f4xx.h"


enum LEDN
{ 
  LED1,
	LED2,
	LED3,
	LED4
};


void LED_Init(void);
void streamLED(void);
void Light(enum LEDN led);

#endif
