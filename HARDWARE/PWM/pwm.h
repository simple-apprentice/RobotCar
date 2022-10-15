#ifndef __PWM_H
#define __PWM_H
#include "stm32f10x.h"
#include "sys.h"

//*****������ƶ˹ܽ�λ����
#define in2 PBout(12) //��1
#define in4 PBout(13) //��1
#define in6 PBout(14) //��2 
#define in8 PBout(15) //��2



void TIM4_PWM_Init(void);
void GPIO_motorconfig_init(void);	//****�������IO��ʼ��
void gostraght(void);
void goright(void);
void goleft(void);
void goback(void);
void gostop(void);
void goright_90(void);//����90��
void goleft_90(void);//����90��

#endif

