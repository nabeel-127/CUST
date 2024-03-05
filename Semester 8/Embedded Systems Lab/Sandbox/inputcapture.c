#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "lcd16x2.h"
#include "delay.h"
#include "stdio.h"

void GPIO_config(void);
void delay(unsigned int ncount);
void timer_init(void);
void NVIC_config(void);
//void TIM2_IRQHandler(void);

GPIO_InitTypeDef gpsi;
TIM_TimeBaseInitTypeDef Time;  
TIM_ICInitTypeDef tim_1;
//TIM_OCInitTypeDef tim_2;
//	uint16_t c,p=0,q=0;
//	uint16_t d;
	float Frequency1;
	float DUTYcycle;
	int flag;
	char sAdcValue[5];
	float frequency=0;
	float value1=0,value2=0;
	float pulse=0;
	int cnt;
int count=0;
float freq=0;
float cap;
unsigned int counts[2];
int main(void)
{
	GPIO_config();
	timer_init();
	NVIC_config();
	TIM_Cmd(TIM2,ENABLE);

lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_OFF);
//	lcd16x2_puts("Count");
//	DelayMs(10);
//	lcd16x2_gotoxy(7,2);
//	
//		
		lcd16x2_puts("Frequency");
//		lcd16x2_puts("Ahmed Ali");
//		lcd16x2_gotoxy(1,0);
		DelayMs(10);
	//lcd16x2_clrscr();
//		else
	
	
	while(1)
	{
//		if(TIM_GetCounter(TIM2)>0 && TIM_GetCounter(TIM2)<7999)
//		{
//			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
//		}
//		DelayInit();

    // LCD initialization
//    d=p-q;
//		c=q;
//		pulse = c/d;
//		frequency = 16000/d;
//		DUTYcycle = pulse*100;
//		Frequency1 = frequency/1000;
//			{
//		GPIO_SetBits(GPIOB,GPIO_Pin_1);
//		}
		if(flag==1)
		{
//			sprintf(sAdcValue, "%d", d);
//			lcd16x2_gotoxy(1,1);
//			lcd16x2_puts(sAdcValue);
//			DelayMs(10);
//			lcd16x2_gotoxy(1,1);
//			lcd16x2_puts("Frequency");
			lcd16x2_gotoxy(3,2);
			sprintf(sAdcValue, "%0.001f",Frequency1);
			lcd16x2_puts(sAdcValue);
			DelayMs(10);
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		}
		else
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_1);
		}
//		cnt = TIM_GetCounter(TIM2);
//		sprintf(sAdcValue, "%d",cnt);
//		lcd16x2_puts(sAdcValue);
//		lcd16x2_gotoxy(7,2);
//		DelayMs(30);
	}

}
void GPIO_config(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	gpsi.GPIO_Pin=GPIO_Pin_1;
	gpsi.GPIO_Mode=GPIO_Mode_Out_PP;
	gpsi.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&gpsi);
}
void timer_init(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	Time.TIM_ClockDivision=TIM_CKD_DIV2;
	Time.TIM_CounterMode=TIM_CounterMode_Up;
	Time.TIM_RepetitionCounter=0;
  Time.TIM_Period=15999;
	Time.TIM_Prescaler=499;
	TIM_TimeBaseInit(TIM2,&Time);
	tim_1.TIM_ICPolarity=TIM_ICPolarity_Rising;
	tim_1.TIM_Channel=TIM_Channel_2;
	tim_1.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	tim_1.TIM_ICSelection=TIM_ICSelection_DirectTI ;
	tim_1.TIM_ICFilter=0;
	TIM_ICInit(TIM2,&tim_1);
	TIM_ITConfig(TIM2,TIM_IT_CC2,ENABLE);
}
void NVIC_config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}
void TIM2_IRQHandler(void)
{
	
	unsigned int counts[2];
	int index=0;
//	value1=TIM2->CCR2;
	
//	counts[count]=TIM_GetCapture2(TIM2);
//	count++;
//	
//	if(count==2)
//	{
//		freq=8000000.0/((counts[1]-counts[0])*(500));
//		count=0;
//		Frequency1=freq;
//		flag=1;
//	}
	
	if(TIM_GetITStatus(TIM2,TIM_IT_CC2)==SET)
		{
			if(count==0)
			{
			value1 = TIM_GetCapture2(TIM2);
			count=1;
				TIM_SetCompare2(TIM2, 0);
				TIM_ClearFlag(TIM2,TIM_IT_CC2);
				
				//TIM_GetITStatus(TIM2,TIM_CC2)=0;
			}
			else if(count==1)
			{
				value2= TIM_GetCapture2(TIM2);
				count=0;
				if(value2>value1)
				{
					cap=value2-value1;
					
				}
				else
				{
					cap=(15999-value1)+value2;
				}
				//frequency=cap/(8*500);
				Frequency1=8000000.0/(cap*500);
				if(Frequency1!=0)
					{flag=1;}
				TIM_SetCompare2(TIM2, 0);
				TIM_ClearFlag(TIM2,TIM_IT_CC2);
			}
			
			
		}
	
//		d=p-q;
//		c=q;
//		//pulse = c/d;
//		frequency = 16000/(d*2);
//		//DUTYcycle = (u32)(pulse*100);
//		Frequency1 = frequency;
		
//	TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
	
	}
//int measurepulsewidth(void)
//{int fedge,redge;
//	while(1)
//	{
//	TIM2->CCR2=4;
//	while(TIM2->SR && (1<<2)==0);
//	fedge=TIM2->
//	}
//}

////#include "stm32f10x.h" 
////#include "stm32f10x_rcc.h" 
////#include "stm32f10x_gpio.h"
////#include "stm32f10x_tim.h" 
////#include "lcd16x2.h" 
////#include "delay.h" 
////#include "stdio.h"


////void GPIO_config(void); 
////void delay (unsigned int ncount); 
////void timer_init(void); 
////void NVIC_config(void); 

////GPIO_InitTypeDef gpsi; 
////TIM_TimeBaseInitTypeDef Time; 
////TIM_ICInitTypeDef tim_1;  

////	float Frequencyl; 
////	float DUTYcycle; 
////	int flag; 
////	char sAdcValue [5]; 
////	float frequency=0; 
////	float valuel=0, value2=0;
////	float pulse=0;
////	int cnt; 
////	int count=0;


////float freq=0; 
////float cap; 
////unsigned int counts[2]; 

////int main(void)
////{
////	GPIO_config(); 
////	timer_init(); 
////	NVIC_config(); 
////	TIM_Cmd(TIM2, ENABLE);

////lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_OFF); 

////lcd16x2_puts("Frequency"); 
////DelayMs (10); 
////while(1)
////{
////	if(flag==1)
////	{		
////		lcd16x2_gotoxy (3,2); 
////		sprintf(sAdcValue,"%0.001f",Frequencyl);
////	lcd16x2_puts(sAdcValue); 	
////		DelayMs(10); 
////		GPIO_ResetBits (GPIOB, GPIO_Pin_1);
////	}
////	else
////	{
////		GPIO_SetBits (GPIOB, GPIO_Pin_1);
////	}
////}
////}

////void GPIO_config(void)
////{
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
////	gpsi.GPIO_Pin = GPIO_Pin_1; 
////	gpsi.GPIO_Mode = GPIO_Mode_Out_PP;
////	gpsi.GPIO_Speed = GPIO_Speed_2MHz;
////	GPIO_Init(GPIOB, &gpsi);
////}

////void timer_init(void)
////{
////	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
////	Time.TIM_ClockDivision = TIM_CKD_DIV1; 
////	Time.TIM_CounterMode = TIM_CounterMode_Up; 
////	Time.TIM_RepetitionCounter = 0; 
////	Time.TIM_Period = 15999; 
////	Time.TIM_Prescaler = 499;
////	TIM_TimeBaseInit(TIM2, &Time);
////	tim_1.TIM_ICPolarity = TIM_ICPolarity_Rising; 
////	tim_1.TIM_Channel = TIM_Channel_2; 
////	tim_1.TIM_ICPrescaler = TIM_ICPSC_DIV2; 
////	tim_1.TIM_ICSelection = TIM_ICSelection_DirectTI; 
////	tim_1.TIM_ICFilter = 0; 
////	TIM_ICInit(TIM2, &tim_1); 
////	TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
////}


////void NVIC_config(void)
////{
////	NVIC_InitTypeDef NVIC_InitStruct;
////	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn; 
////	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00; 
////	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00; 
////	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; 
////	NVIC_Init(&NVIC_InitStruct);
////}

////void TIM2_IRQHandler(void)
////{
////	unsigned int counts[2];
////	int index=0; 
////	
////	if(TIM_GetITStatus(TIM2, TIM_IT_CC2)==SET)
////	{
////		if (count==0)
////		{
////			valuel = TIM_GetCapture2(TIM2); 
////			count = 1;
////			TIM_SetCompare2(TIM2, 0); 
////			TIM_ClearFlag(TIM2, TIM_IT_CC2);
////	
////		}

////		else if(count==1)
////		{
////			value2= TIM_GetCapture2(TIM2); 
////			count=0; 
////			
////			if(value2>valuel)
////			{
////				cap = value2-valuel;
////			}

////			else
////			{
////				cap=(15999-valuel) +value2;
////			}
////					
////			Frequencyl = 3*8000000.0/(cap*500);
////			 if(Frequencyl!=0)

////			{ flag=1; } 
////			
////			TIM_SetCompare2 (TIM2, 0);
////			TIM_ClearFlag (TIM2, TIM_IT_CC2);
////		}
////}
////}
////	