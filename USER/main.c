#include "car.h"
#include "delay.h"
#include "led.h"
#include "interrupt.h"
#include "uartTest.h"


int main(void)
{
	delay_init(168);
	//LED_Init();	
	INTERRUPT_Init();
	dianji_Init();
	allRun000();
	uart2();
	while(1){
		//xunzhi();
	}
}


/*
#include "uartTest.h"
#include "led.h"
#include "beep.h"
#include "interrupt.h"

int main(void)
{
	LED_Init();
	BEEP_Init();
	//INTERRUPT_Init();
	allRun000();
	uart2();
	while(1){
		
	}
}
*/

/*
//按键中断
#include "stm32f4xx.h"
#include "interrupt.h"
#include "led.h"
#include "delay.h"
#include "beep.h"

int main(void)
{
	LED_Init();

	delay_init(168);
	INTERRUPT_Init();
	while(1){
		
	}
}
*/

/*
//按键代码
#include "stm32f4xx.h"
#include "led.h"
#include "key.h"
#include "beep.h"
#include "delay.h"


int main(void)
{
	LED_Init();
	BEEP_Init();
	delay_init(168);
	KEY_Init();
	while(1)
		{
			RunKey();
	}
}
*/


