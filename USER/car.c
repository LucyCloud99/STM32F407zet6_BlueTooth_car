#include "car.h"
#include "delay.h"


void dianji_Init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct={
		GPIO_Pin_6|GPIO_Pin_7,
		GPIO_Mode_OUT,
		GPIO_Fast_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
		GPIO_InitTypeDef GPIO_InitStruct2={
		GPIO_Pin_6|GPIO_Pin_7,
		GPIO_Mode_OUT,
		GPIO_Fast_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_UP
	};
		GPIO_InitTypeDef GPIO_InitStruct3={
		GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11,
		GPIO_Mode_IN,
		GPIO_Fast_Speed,
		GPIO_OType_PP,
		GPIO_PuPd_NOPULL
	};
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	GPIO_Init(GPIOB,&GPIO_InitStruct2);
	GPIO_Init(GPIOC,&GPIO_InitStruct3);
}

void dianji_status(enum STATUS status){
	switch (status){
		case run:
			GPIO_SetBits(GPIOB,GPIO_Pin_6);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		  GPIO_SetBits(GPIOD,GPIO_Pin_6);
			GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			break;
		case left_forward:
			GPIO_SetBits(GPIOB,GPIO_Pin_6);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7);
			delay_ms(50);
			break;
		case right_forward:
			GPIO_SetBits(GPIOD,GPIO_Pin_6);
			GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			delay_ms(50);
			break;
		case left_back:
			GPIO_SetBits(GPIOB,GPIO_Pin_7);
			GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			delay_ms(50);
			break;
		case right_back:
			GPIO_SetBits(GPIOD,GPIO_Pin_7);
			GPIO_ResetBits(GPIOD,GPIO_Pin_6);
			delay_ms(50);
			break;
		case back:
			GPIO_SetBits(GPIOB,GPIO_Pin_7);
			GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		  GPIO_SetBits(GPIOD,GPIO_Pin_7);
			GPIO_ResetBits(GPIOD,GPIO_Pin_6);
			delay_ms(50);
			break;
		case stop:
			GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			GPIO_ResetBits(GPIOD,GPIO_Pin_6);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7);
			GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			delay_ms(50);
			break;
		default:
			break;
	}
};

//void go_forward(void){
//	enum STATUS st = run;
//	dianji_status(st);
//}

//void go_back(){
//	enum STATUS st = back;
//	dianji_status(st);
//};

//void go_stop(void){
//	enum STATUS st = stop;
//	dianji_status(st);
//}

//void go_left(void){
//	go_stop();
//	enum STATUS st = right_forward;
//	dianji_status(st);
//}

//void go_right(void){
//	go_stop();
//	enum STATUS st = left_forward;
//	dianji_status(st);
//}

//void go_roundleft(void){
//	enum STATUS st = left_back;
//	dianji_status(st);
//	dianji_status(st = right_forward);
//}

//void go_roundright(void){
//	enum STATUS st = left_forward;
//	dianji_status(st);
//	dianji_status(st = right_back);
//}

void go_forward(void){
	enum STATUS st = run;
	dianji_status(st);
}

void go_back(){
	enum STATUS st = back;
	dianji_status(st);
};

void go_stop(void){
	enum STATUS st = stop;
	dianji_status(st);
}

void go_left(void){
	go_stop();
	enum STATUS st = right_forward;
	dianji_status(st);
}

void go_right(void){
	go_stop();
	enum STATUS st = left_forward;
	dianji_status(st);
}

void go_roundleft(void){
	enum STATUS st = left_back;
	dianji_status(st);
	dianji_status(st = right_forward);
}

void go_roundright(void){
	enum STATUS st = left_forward;
	dianji_status(st);
	dianji_status(st = right_back);
}

void test(){
		go_roundright();
	}

void xunzhi(void){
	
	uint8_t a;
	uint8_t b;
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) != a || GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) != b){
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == 0x00 && GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == 0x00)
	{
		go_forward();
		USART_SendData(USART1,'a');while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	}
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == 0x00 && GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == 0x01)
	{
		go_right();
		USART_SendData(USART1,'b');while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	}
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == 0x01 && GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == 0x00)
	{
		go_left();
		USART_SendData(USART1,'c');while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
		
	}
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == 0x01 && GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == 0x01)
	{
		go_stop();
		USART_SendData(USART1,'d');while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	}
	
}
};

