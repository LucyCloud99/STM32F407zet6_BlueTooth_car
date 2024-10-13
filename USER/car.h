#ifndef __CAR_H__
#define __CAR_H__
		
#include "stm32f4xx.h"

enum STATUS{
	run,
	left_forward,
	right_forward,
	left_back,
	right_back,
	back,
	stop
};

void dianji_Init(void);
void dianji_status(enum STATUS status);
void test(void);
void go_forward(void);
void go_back(void);
void go_stop(void);
void go_left(void);
void go_right(void);
void go_roundleft(void);
void go_roundright(void);
void xunzhi(void);


#endif
