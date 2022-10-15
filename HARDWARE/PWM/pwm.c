#include "pwm.h"
#include "delay.h"

void TIM4_PWM_Init()
{  
	 GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;

	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//������ʱ����ʱ�� ����ʱ��ʱ����72MHZ
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //����GPIOB��ʱ��
  //����TIM4_CH1��TIM4_CH2��TIM4_CH3��TIM4_CH4���������
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//in1 in3 in5 in7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
   //��ʱ���Ļ�������		 
  TIM_TimeBaseStructure.TIM_Period = 1000-1;     //����ʱ����0������999����Ϊ1000�Σ�Ϊһ����ʱ����
  TIM_TimeBaseStructure.TIM_Prescaler =0;	    //����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ	
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
   
	//����TIM4_CH1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_Pulse = 0;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //���ñȽ��������Ч��ƽ
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);	
	//����TIM4_CH2
	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_Pulse = 0;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //���ñȽ��������Ч��ƽ
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);	
	//����TIM4_CH3
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_Pulse = 0;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //���ñȽ��������Ч��ƽ
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);	
  //����TIM4_CH4
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_Pulse = 0;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //���ñȽ��������Ч��ƽ
  TIM_OC4Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);	

  TIM_ARRPreloadConfig(TIM4, ENABLE);			 // ʹ��TIM4���ؼĴ���ARR

  TIM_Cmd(TIM4, ENABLE);                   //ʹ�ܶ�ʱ��4
} 
	

void GPIO_motorconfig_init(void)	//****�������IO��ʼ��
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
}

void gostraght(void)   //0-1000 ��ֵԽ��ת��Խ�� �ı���ֵ���Ǳ���ѭ��
{
	
	TIM_SetCompare1(TIM4,400);  // ��1
	in2=0;
	TIM_SetCompare2(TIM4,400);   // ��1
	in4=0;
	TIM_SetCompare3(TIM4,400);  // ��2
	in6=0;
	TIM_SetCompare4(TIM4,400);  // ��2
	in8=0;
}

void goright(void)//ǰ��
{
	TIM_SetCompare1(TIM4,250);  // ��1
	in2=0;
	TIM_SetCompare2(TIM4,500);   // ��1
	in4=0;
	TIM_SetCompare3(TIM4,250);  // ��2
	in6=0;
	TIM_SetCompare4(TIM4,500);  // ��2
	in8=0;
}

void goleft(void)//ǰ��
{
	TIM_SetCompare1(TIM4,500);  // ��1
	in2=0;
	TIM_SetCompare2(TIM4,250);   // ��1
	in4=0;
	TIM_SetCompare3(TIM4,500);  // ��2
	in6=0;
	TIM_SetCompare4(TIM4,250);  // ��2
	in8=0;
}

void goback(void)
{
	TIM_SetCompare1(TIM4,600);  // ��1
	in2=1;
	TIM_SetCompare2(TIM4,600);   // ��1
	in4=1;
	TIM_SetCompare3(TIM4,600);  // ��2
	in6=1;
	TIM_SetCompare4(TIM4,600);  // ��2
	in8=1;
}


void goright_90(void)//
{
//	TIM_SetCompare1(TIM4,0);  // ��1
//	in2=0;
//	TIM_SetCompare2(TIM4,700);   // ��1
//	in4=0;
//	TIM_SetCompare3(TIM4,0);  // ��2
//	in6=0;
//	TIM_SetCompare4(TIM4,700);  // ��2
//	in8=0;
	TIM_SetCompare1(TIM4,600);  // ��1
	in2=1;
	TIM_SetCompare2(TIM4,500);   // ��1
	in4=0;
	TIM_SetCompare3(TIM4,600);  // ��2
	in6=1;
	TIM_SetCompare4(TIM4,500);  // ��2
	in8=0;
}

void goleft_90(void)//����90��
{
//	TIM_SetCompare1(TIM4,700);  // ��1
//	in2=0;
//	TIM_SetCompare2(TIM4,0);   // ��1
//	in4=0;
//	TIM_SetCompare3(TIM4,700);  // ��2
//	in6=0;
//	TIM_SetCompare4(TIM4,0);  // ��2
//	in8=0;
	TIM_SetCompare1(TIM4,400);  // ��1
	in2=0;
	TIM_SetCompare2(TIM4,600);   // ��1
	in4=1;
	TIM_SetCompare3(TIM4,400);  // ��2
	in6=0;
	TIM_SetCompare4(TIM4,600);  // ��2
	in8=1;
}

void gostop(void) 
{
	TIM_SetCompare1(TIM4,0);  // ��1
	in2=0;
	TIM_SetCompare2(TIM4,0);   // ��1
	in4=0;
	TIM_SetCompare3(TIM4,0);  // ��2
	in6=0;
	TIM_SetCompare4(TIM4,0);  // ��2
	in8=0;
}

