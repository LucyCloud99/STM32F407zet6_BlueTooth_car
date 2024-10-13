#include "uartTest.h"
#include "car.h"
#include "delay.h"

void uart2(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
		GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_2|GPIO_Pin_3,
		GPIO_Mode_AF,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART1);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	USART_InitTypeDef USART_InitStruct = {
		9600,
		USART_WordLength_8b,
		USART_StopBits_1,
		USART_Parity_No,
		USART_Mode_Rx|USART_Mode_Tx,
		USART_HardwareFlowControl_None
	};
	USART_Init(USART2,&USART_InitStruct);
	
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStruct = {
		USART2_IRQn,
		0x00,
		0x02,
		ENABLE
	};
	
	NVIC_Init(&NVIC_InitStruct);
	USART_Cmd(USART2,ENABLE);
}

void allRun000(){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
		GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_9|GPIO_Pin_10,
		GPIO_Mode_AF,
		GPIO_Medium_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	USART_InitTypeDef USART_InitStruct = {
		9600,
		USART_WordLength_8b,
		USART_StopBits_1,
		USART_Parity_No,
		USART_Mode_Rx|USART_Mode_Tx,
		USART_HardwareFlowControl_None
	};
	USART_Init(USART1,&USART_InitStruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStruct = {
		USART1_IRQn,
		0x00,
		0x02,
		ENABLE
	};
	
	NVIC_Init(&NVIC_InitStruct);
	USART_Cmd(USART1,ENABLE);
}

void USART2_IRQHandler(){
	if(USART_GetITStatus(USART2,USART_IT_RXNE) == SET)
		{
			u8 data = (USART_ReceiveData(USART2));
			switch (data){
				case 'a':
					GPIO_ResetBits(GPIOF,GPIO_Pin_9);
					break;
				case 'A':
					GPIO_SetBits(GPIOF,GPIO_Pin_9);
					break;
				case 'c':
					GPIO_SetBits(GPIOF,GPIO_Pin_8);
					break;
				case 'B':
					GPIO_ResetBits(GPIOF,GPIO_Pin_8);
					break;
				case 'g':
					go_forward();
					delay_ms(10);
					if(USART_GetITStatus(USART2,USART_IT_RXNE) == SET){while(USART_GetITStatus(USART2,USART_IT_RXNE) == SET){};go_stop();}
					break;
				case 'b':
					go_back();
					break;
				case 's':
					go_stop();
					break;
				case 'l':
					go_left();
					break;
				case 'r':
					go_right();
					break;
				case 't':
					go_roundleft();
					break;
				case 'p':
					go_roundright();
					break;
				default:
					break;
				}
		}
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
};

void USART1_IRQHandler(){
//		char Data[] = "number==";
//		for(int i = 0 ; i < 8;i++){
//			USART_SendData(USART1,Data[i]);
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
//		}
	
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
		{
			u8 data = (USART_ReceiveData(USART1));
switch (data){
				case 'a':
					GPIO_ResetBits(GPIOF,GPIO_Pin_9);
					break;
				case 'A':
					GPIO_SetBits(GPIOF,GPIO_Pin_9);
					break;
				case 'c':
					GPIO_SetBits(GPIOF,GPIO_Pin_8);
					break;
				case 'B':
					GPIO_ResetBits(GPIOF,GPIO_Pin_8);
					break;
				case 'g':
					go_forward();
					delay_ms(100);
					while(USART_GetITStatus(USART2,USART_IT_RXNE) == SET){}
					go_stop();
					break;
				case 'b':
					go_back();
					break;
				case 's':
					go_stop();
					break;
				case 'l':
					go_left();
					break;
				case 'r':
					go_right();
					break;
				case 't':
					go_roundleft();
					break;
				case 'p':
					go_roundright();
					break;
				default:
					break;
				}
		}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
};
