#ifndef __TRACE_H
#define __TRACE_H
#include "stm32f10x.h"
#include "sys.h"

//*****循迹 从左至右依次为IR1，IR2，IR3，IR4
#define IR1 PAin(1) //右1
#define IR2 PAin(2) //左1
#define IR3 PAin(3) //右2 
#define IR4 PAin(6) //左2
//****循迹标志位
#define flag_IR1 1
#define flag_IR2 5
#define flag_IR3 10
#define flag_IR4 2

//*****避障 
#define AVOID PCin(15) 


void GPIO_IR_init(void);	//****电机驱动IO初始化
void GPIO_avoid_init(void); //避障初始化
void IR_trace(void);
u8 SearchSignal(void);
void trace_online(void);	

#endif

