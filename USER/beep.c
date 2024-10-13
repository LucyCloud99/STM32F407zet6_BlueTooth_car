#include "beep.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"

void BEEP_Init(void);
void RunBeep(void);

void BEEP_Init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_8,
		GPIO_Mode_OUT,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
	GPIO_Init(GPIOF,&GPIO_InitStruct);
	delay_init(168);
	GPIO_WriteBit(GPIOF,GPIO_Pin_8,Bit_RESET);
}

void RunBeep(void){
	GPIO_WriteBit(GPIOF,GPIO_Pin_8,Bit_SET);
	GPIO_ToggleBits(GPIOE,GPIO_Pin_14);
	delay_ms(1000);
	GPIO_WriteBit(GPIOF,GPIO_Pin_8,Bit_RESET);
	GPIO_ToggleBits(GPIOE,GPIO_Pin_14);
	delay_ms(1000);	
}
