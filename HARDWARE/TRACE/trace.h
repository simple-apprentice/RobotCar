#ifndef __TRACE_H
#define __TRACE_H
#include "stm32f10x.h"
#include "sys.h"

//*****ѭ�� ������������ΪIR1��IR2��IR3��IR4
#define IR1 PAin(1) //��1
#define IR2 PAin(2) //��1
#define IR3 PAin(3) //��2 
#define IR4 PAin(6) //��2
//****ѭ����־λ
#define flag_IR1 1
#define flag_IR2 5
#define flag_IR3 10
#define flag_IR4 2

//*****���� 
#define AVOID PCin(15) 


void GPIO_IR_init(void);	//****�������IO��ʼ��
void GPIO_avoid_init(void); //���ϳ�ʼ��
void IR_trace(void);
u8 SearchSignal(void);
void trace_online(void);	

#endif

