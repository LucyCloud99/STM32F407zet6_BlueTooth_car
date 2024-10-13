#include "led.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"

void streamLED(void){
	delay_ms(1000);
	GPIO_SetBits(GPIOF,GPIO_Pin_9);
	GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	delay_ms(1000);
	GPIO_SetBits(GPIOF,GPIO_Pin_10);
	GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	delay_ms(1000);
	GPIO_SetBits(GPIOE,GPIO_Pin_13);
	GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	delay_ms(1000);
	GPIO_SetBits(GPIOE,GPIO_Pin_14);
	GPIO_ResetBits(GPIOF,GPIO_Pin_9);
	delay_ms(1000);
	GPIO_WriteBit(GPIOF,GPIO_Pin_9|GPIO_Pin_10,Bit_SET);
	GPIO_WriteBit(GPIOE,GPIO_Pin_13|GPIO_Pin_14,Bit_SET);	
}


void Light(enum LEDN led)
	{
		switch (led){
			case LED1:
				GPIO_ResetBits(GPIOF,GPIO_Pin_9);
				break;
			case LED2:
				GPIO_ResetBits(GPIOF,GPIO_Pin_10);
				break;
			case LED3:
				GPIO_ResetBits(GPIOE,GPIO_Pin_13);
				break;
			case LED4:
				GPIO_ResetBits(GPIOE,GPIO_Pin_14);
				break;
			default:
				break;
		}
	}

void LED_Init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_9|GPIO_Pin_10,
		GPIO_Mode_OUT,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
		GPIO_InitTypeDef GPIO_InitStruct2={
		GPIO_Pin_13|GPIO_Pin_14,
		GPIO_Mode_OUT,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
	GPIO_Init(GPIOF,&GPIO_InitStruct);
	GPIO_Init(GPIOE,&GPIO_InitStruct2);
	GPIO_WriteBit(GPIOF,GPIO_Pin_9|GPIO_Pin_10,Bit_SET);
	GPIO_WriteBit(GPIOE,GPIO_Pin_13|GPIO_Pin_14,Bit_SET);	
}
