#include "key.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"
#include "led.h"
#include "beep.h"


void KEY_Init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_0,
		GPIO_Mode_IN,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
		GPIO_InitTypeDef GPIO_InitStruct2={
		GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4,
		GPIO_Mode_IN,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOE,&GPIO_InitStruct2);
}

void RunKey(void){
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
	{
		delay_ms(80);
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_9);
			GPIO_ToggleBits(GPIOE,GPIO_Pin_13);
			while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0){}
		}
	}
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
	{
		delay_ms(80);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_10);
			GPIO_ToggleBits(GPIOE,GPIO_Pin_14);
			while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0){}
		}
	}
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)
	{
		delay_ms(80);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)
		{
			RunBeep();
			while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0){}
		}
	}
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0)
	{
		delay_ms(80);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0)
		{
			streamLED();
			while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0){}
		}
	}
	else{}
}
