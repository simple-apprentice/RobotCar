#include "trace.h"
#include "pwm.h"

void GPIO_IR_init(void)	//****灰度循迹IO初始化  默认为白色低电平，绿色高电平
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					
}

void GPIO_avoid_init(void)	//****避障IO初始化  检测到目标是低电平输出，正常状态是高电平输出
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					
}


u8 SearchSignal(void)
{
	u8 Signal_back=0;
	if(IR1==0)
	 Signal_back+=flag_IR1;
	if(IR2==0)
	 Signal_back+=flag_IR2;
	if(IR3==0)
	 Signal_back+=flag_IR3;
	if(IR4==0)
	Signal_back+=flag_IR4;
	 return Signal_back;
}	

void trace_online(void)			//白0 绿1
{
	u8 signal_online=0;
	signal_online=SearchSignal();
	if(signal_online==15) //直走
	{
		gostraght();
	}
	else if((signal_online==6)||(signal_online==1)||(signal_online==5)) //左转
	{
		goleft();
	}
	else if((signal_online==12)||(signal_online==2)||(signal_online==10)) //右转
	{
		goright();
	}
	else if((signal_online==16))	 //90左转 直角
	{  	 	   
		 do{goleft_90();}
		 while(IR2==0||IR3==0);
	}
	else if((signal_online==17))	 //90右转 直角
	{
		gostraght();
  delay_ms(10);
			gostop();
			delay_ms(100);
		do{
		
			
		goright_90();}
		while(IR2==0||IR3==0);
	}
   	else if(signal_online==18) //出发点T字路口 默认右转
	{
	  do{goright_90();}
		while(IR2==0||IR3==0);			
	 }
	else if(signal_online==0)
	{
		goright_90();
	}

}




