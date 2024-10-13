#include "interrupt.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "car.h"

void INTERRUPT_Init(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_0,
		GPIO_Mode_IN,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
	GPIO_InitTypeDef GPIO_InitStruct1={
		GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4,
		GPIO_Mode_IN,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOE,&GPIO_InitStruct1);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC,EXTI_PinSource10);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC,EXTI_PinSource11);

	
	EXTI_InitTypeDef EXTI_InitStruct = {
		EXTI_Line0,
		EXTI_Mode_Interrupt,
		EXTI_Trigger_Falling,
		ENABLE
	};
	EXTI_InitTypeDef EXTI_InitStruct1 = {
		EXTI_Line2|EXTI_Line3|EXTI_Line4,
		EXTI_Mode_Interrupt,
		EXTI_Trigger_Falling,
		ENABLE
	};
//		EXTI_InitTypeDef EXTI_InitStruct2 = {
//		EXTI_Line10|EXTI_Line11,
//		EXTI_Mode_Interrupt,
//		EXTI_Trigger_Falling,
//		ENABLE
//	};
	EXTI_Init(&EXTI_InitStruct);
	EXTI_Init(&EXTI_InitStruct1);	
	//EXTI_Init(&EXTI_InitStruct2);		
	
	NVIC_InitTypeDef NVIC_InitStruct = {
		EXTI0_IRQn,
		0x00,
		0x02,
		ENABLE
	};
	NVIC_InitTypeDef NVIC_InitStruct1 = {
		EXTI2_IRQn,
		0x01,
		0x02,
		ENABLE
	};
	NVIC_InitTypeDef NVIC_InitStruct2 = {
		EXTI3_IRQn,
		0x02,
		0x02,
		ENABLE
	};
	NVIC_InitTypeDef NVIC_InitStruct3 = {
		EXTI4_IRQn,
		0x03,
		0x02,
		ENABLE
	};
//	NVIC_InitTypeDef NVIC_InitStruct4 = {
//		EXTI15_10_IRQn,
//		0x00,
//		0x02,
//		ENABLE
//	};	
	
	NVIC_Init(&NVIC_InitStruct);
	NVIC_Init(&NVIC_InitStruct1);	
	NVIC_Init(&NVIC_InitStruct2);
	NVIC_Init(&NVIC_InitStruct3);
	//NVIC_Init(&NVIC_InitStruct4);	
}


void EXTI0_IRQHandler(void)
{
	delay_ms(80);	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)	 
	{
//		char Data[] = "hello!!!";
//		for(int i = 0 ; i < 8;i++){
//			USART_SendData(USART1,Data[i]);
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
//		}
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);
		GPIO_ToggleBits(GPIOF,GPIO_Pin_9);
		go_forward();
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line0); 
}

void EXTI2_IRQHandler(void)
{
	delay_ms(80);	
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)	 
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);
		GPIO_ToggleBits(GPIOF,GPIO_Pin_10);
		go_back();
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line2); 
}

void EXTI3_IRQHandler(void)
{
	delay_ms(80);	
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)	 
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);
		GPIO_ToggleBits(GPIOE,GPIO_Pin_13);
		go_left();
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line3); 
}

void EXTI4_IRQHandler(void)
{
	delay_ms(80);	
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0)	 
	{
		//RunBeep();
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);
		GPIO_ToggleBits(GPIOE,GPIO_Pin_14);		
		go_roundleft();
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line4); 
}
