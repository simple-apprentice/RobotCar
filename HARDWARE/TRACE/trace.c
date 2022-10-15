#include "trace.h"
#include "pwm.h"

void GPIO_IR_init(void)	//****�Ҷ�ѭ��IO��ʼ��  Ĭ��Ϊ��ɫ�͵�ƽ����ɫ�ߵ�ƽ
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					
}

void GPIO_avoid_init(void)	//****����IO��ʼ��  ��⵽Ŀ���ǵ͵�ƽ���������״̬�Ǹߵ�ƽ���
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
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

void trace_online(void)			//��0 ��1
{
	u8 signal_online=0;
	signal_online=SearchSignal();
	if(signal_online==15) //ֱ��
	{
		gostraght();
	}
	else if((signal_online==6)||(signal_online==1)||(signal_online==5)) //��ת
	{
		goleft();
	}
	else if((signal_online==12)||(signal_online==2)||(signal_online==10)) //��ת
	{
		goright();
	}
	else if((signal_online==16))	 //90��ת ֱ��
	{  	 	   
		 do{goleft_90();}
		 while(IR2==0||IR3==0);
	}
	else if((signal_online==17))	 //90��ת ֱ��
	{
		gostraght();
  delay_ms(10);
			gostop();
			delay_ms(100);
		do{
		
			
		goright_90();}
		while(IR2==0||IR3==0);
	}
   	else if(signal_online==18) //������T��·�� Ĭ����ת
	{
	  do{goright_90();}
		while(IR2==0||IR3==0);			
	 }
	else if(signal_online==0)
	{
		goright_90();
	}

}




