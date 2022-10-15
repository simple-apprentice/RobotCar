#include "pwm.h"
#include "delay.h"

void TIM4_PWM_Init()
{  
	 GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;

	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//开启定时器的时钟 ，定时器时钟是72MHZ
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //开启GPIOB的时钟
  //设置TIM4_CH1和TIM4_CH2和TIM4_CH3和TIM4_CH4的输出引脚
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//in1 in3 in5 in7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
   //定时器的基本设置		 
  TIM_TimeBaseStructure.TIM_Period = 1000-1;     //当定时器从0计数到999，即为1000次，为一个定时周期
  TIM_TimeBaseStructure.TIM_Prescaler =0;	    //设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式	
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
   
	//配置TIM4_CH1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = 0;	   //设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //设置比较输出的有效电平
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);	
	//配置TIM4_CH2
	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = 0;	   //设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //设置比较输出的有效电平
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);	
	//配置TIM4_CH3
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = 0;	   //设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //设置比较输出的有效电平
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);	
  //配置TIM4_CH4
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = 0;	   //设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //设置比较输出的有效电平
  TIM_OC4Init(TIM4, &TIM_OCInitStructure);	 
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);	

  TIM_ARRPreloadConfig(TIM4, ENABLE);			 // 使能TIM4重载寄存器ARR

  TIM_Cmd(TIM4, ENABLE);                   //使能定时器4
} 
	

void GPIO_motorconfig_init(void)	//****电机驱动IO初始化
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
}

void gostraght(void)   //0-1000 数值越大转得越快 改变数值就是变速循迹
{
	
	TIM_SetCompare1(TIM4,400);  // 右1
	in2=0;
	TIM_SetCompare2(TIM4,400);   // 左1
	in4=0;
	TIM_SetCompare3(TIM4,400);  // 右2
	in6=0;
	TIM_SetCompare4(TIM4,400);  // 左2
	in8=0;
}

void goright(void)//前右
{
	TIM_SetCompare1(TIM4,250);  // 右1
	in2=0;
	TIM_SetCompare2(TIM4,500);   // 左1
	in4=0;
	TIM_SetCompare3(TIM4,250);  // 右2
	in6=0;
	TIM_SetCompare4(TIM4,500);  // 左2
	in8=0;
}

void goleft(void)//前左
{
	TIM_SetCompare1(TIM4,500);  // 右1
	in2=0;
	TIM_SetCompare2(TIM4,250);   // 左1
	in4=0;
	TIM_SetCompare3(TIM4,500);  // 右2
	in6=0;
	TIM_SetCompare4(TIM4,250);  // 左2
	in8=0;
}

void goback(void)
{
	TIM_SetCompare1(TIM4,600);  // 右1
	in2=1;
	TIM_SetCompare2(TIM4,600);   // 左1
	in4=1;
	TIM_SetCompare3(TIM4,600);  // 右2
	in6=1;
	TIM_SetCompare4(TIM4,600);  // 左2
	in8=1;
}


void goright_90(void)//
{
//	TIM_SetCompare1(TIM4,0);  // 右1
//	in2=0;
//	TIM_SetCompare2(TIM4,700);   // 左1
//	in4=0;
//	TIM_SetCompare3(TIM4,0);  // 右2
//	in6=0;
//	TIM_SetCompare4(TIM4,700);  // 左2
//	in8=0;
	TIM_SetCompare1(TIM4,600);  // 右1
	in2=1;
	TIM_SetCompare2(TIM4,500);   // 左1
	in4=0;
	TIM_SetCompare3(TIM4,600);  // 右2
	in6=1;
	TIM_SetCompare4(TIM4,500);  // 左2
	in8=0;
}

void goleft_90(void)//向左90°
{
//	TIM_SetCompare1(TIM4,700);  // 右1
//	in2=0;
//	TIM_SetCompare2(TIM4,0);   // 左1
//	in4=0;
//	TIM_SetCompare3(TIM4,700);  // 右2
//	in6=0;
//	TIM_SetCompare4(TIM4,0);  // 左2
//	in8=0;
	TIM_SetCompare1(TIM4,400);  // 右1
	in2=0;
	TIM_SetCompare2(TIM4,600);   // 左1
	in4=1;
	TIM_SetCompare3(TIM4,400);  // 右2
	in6=0;
	TIM_SetCompare4(TIM4,600);  // 左2
	in8=1;
}

void gostop(void) 
{
	TIM_SetCompare1(TIM4,0);  // 右1
	in2=0;
	TIM_SetCompare2(TIM4,0);   // 左1
	in4=0;
	TIM_SetCompare3(TIM4,0);  // 右2
	in6=0;
	TIM_SetCompare4(TIM4,0);  // 左2
	in8=0;
}

