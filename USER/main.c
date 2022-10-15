#include "stm32f10x.h"
#include "sys.h"
#include "pwm.h"
#include "delay.h"
#include "usart2.h"
#include "led.h"
#include "oled.h" 
#include "trace.h"
#include "irda.h"

extern uint8_t  frame_flag;
extern uint8_t  isr_cnt;
extern uint8_t  frame_cnt;

void init()
{
	TIM4_PWM_Init();
	GPIO_motorconfig_init();
	GPIO_IR_init();
	GPIO_avoid_init();
	delay_init();
	LED_Init();
	OLED_Init();		
	
	OLED_Clear();
	IrDa_Init();
}	

void show_oled()
{
	OLED_Clear();
	OLED_ShowCHinese(0,0,0);
  OLED_ShowCHinese(20,0,1);
  OLED_ShowCHinese(40,0,2);
	OLED_ShowString(0,4,"32318316"); 	
}

int main(void)
{  

// 
	uint8_t key_val;
	  u8 flag_IR=0; //红外控制标志位 
	init(); 
  show_oled();
	while(1)
		{ 
			if(AVOID==1)
			{

				trace_online();

			}
			else
			{

				gostop();
				delay_ms(100);
			}}}
//	gostraght();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
//			goback();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
//			goright();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
//			goleft();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
//			
//			goright_90();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
//			goleft_90();
//			delay_ms(1000);
//			gostop();
//			delay_ms(200);
			
//			
//		if( frame_flag == 1 ) /* 一帧红外数据接收完成 */
//		{	
//		 key_val = IrDa_Process();
//		 if(key_val==162) //开/关红外遥控
//      flag_IR=!flag_IR;
//		 if(flag_IR)
//		 {	 
//				switch( key_val )
//				{			
//					case 2: 
//					gostraght();
//					break;
//					
//					case 224:
//					goleft_90();
//					break;
//					
//					case 144:
//					goright_90();
//					break;
//					
//					case 152:
//					goback();
//					break;
//					
//					case 168:
//					gostop();
//					break;
//			 }
//		 }			

				
	

 