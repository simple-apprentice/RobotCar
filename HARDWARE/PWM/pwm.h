#ifndef __PWM_H
#define __PWM_H
#include "stm32f10x.h"
#include "sys.h"

//*****电机控制端管脚位定义
#define in2 PBout(12) //右1
#define in4 PBout(13) //左1
#define in6 PBout(14) //右2 
#define in8 PBout(15) //左2



void TIM4_PWM_Init(void);
void GPIO_motorconfig_init(void);	//****电机驱动IO初始化
void gostraght(void);
void goright(void);
void goleft(void);
void goback(void);
void gostop(void);
void goright_90(void);//向右90°
void goleft_90(void);//向左90°

#endif

