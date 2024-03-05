
#include "stm32f10x_tim.h"


#include "delay.h" 
#include "lcd16x2.h"


#include "stm32f10x_tim.h"
#include "lcd16x2.h"
#include "delay.h"
#include "stdio.h"


#include "stm32f10x_adc.h"
#include <stdio.h>



void ADC1_Init(void);
uint16_t ADC1_Read(void);

uint16_t adcValue;
char sAdcValue[5];



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



void configureKeyPadpins(void);

void SetColumnsLow(void); 
void SetColumn_1(void);
void SetColumn_2(void); 
void SetColumn_3(void); 
void Delay(unsigned int nCount);

void KeyPad_Scan(void);

int Col_1 =0; 
int Col_2=0; 
int Col_3=0;

GPIO_InitTypeDef myLED;

void pwminit(void);
void GPIOinit(void);
void msdelay(unsigned int ncount);
GPIO_InitTypeDef gpioinit;

int bright;

int main(void)
{
	float voltage;
	
	DelayInit();
	lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
	
	lcd16x2_puts("VOLTAGE = ");
	lcd16x2_gotoxy(3,2);

	DelayMs(10);
	
	// Initialize ADC
	ADC1_Init();
	
	while (1)
	{
		// Read ADC value
		adcValue = ADC1_Read();
		
		// Convert ADC value to Voltage using formulae
		voltage = (float)adcValue/4096 * 3.3; 	
		
		// Convert Voltage(float) into Voltage(string)
		sprintf(sAdcValue, "%0.1f v", voltage);
		
		// Display ADC value to LCD
		lcd16x2_gotoxy(3,2);
		lcd16x2_puts(sAdcValue);

		DelayMs(5);
	}
	
	
	
	GPIO_config();
	timer_init();
	NVIC_config();
	TIM_Cmd(TIM2,ENABLE);

lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_OFF);

		lcd16x2_puts("Frequency");

		DelayMs(10);

	
	
	while(1)
	{

		if(flag==1)
		{

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

	}

	
	
	DelayInit();
	// LCD initialization 
	lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_OFF);
	
	configureKeyPadpins();

			lcd16x2_puts("Farakh Ali");
	lcd16x2_gotoxy(7,2); 
	DelayMs(10);
	
	SetColumnsLow();

	while (1)
	{
		SetColumn_1(); 
		DelayMs(1); 
		KeyPad_Scan();

		SetColumn_2(); 
		DelayMs(1); 
		KeyPad_Scan();

		SetColumn_3(); 
		DelayMs(1); 
		KeyPad_Scan();

	}
	
	
	
	
	GPIOinit();
	pwminit();

}

void GPIOinit(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
// Initialize PA0 as push-pull alternate function (PWM output) for LED
gpioinit.GPIO_Pin = GPIO_Pin_1;
gpioinit.GPIO_Mode = GPIO_Mode_AF_OD;
gpioinit.GPIO_Speed = GPIO_Speed_2MHz;
GPIO_Init(GPIOA, &gpioinit);
}


void pwminit(void)
{
TIM_TimeBaseInitTypeDef timeinit;
TIM_OCInitTypeDef ocinit;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
timeinit.TIM_Prescaler = 10;
timeinit.TIM_Period = 7199;
timeinit.TIM_ClockDivision = TIM_CKD_DIV1;
timeinit.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM2, &timeinit);
TIM_Cmd(TIM2, ENABLE);
	
ocinit.TIM_OCMode = TIM_OCMode_PWM1;
ocinit.TIM_OutputState = TIM_OutputState_Enable;
ocinit.TIM_OCPolarity = TIM_OCPolarity_High;
ocinit.TIM_Pulse = 4247;
TIM_OC2Init(TIM2, &ocinit);
	
// Duty cycle calculation equation:
// TIM_Pulse = (((TIM_Period + 1) * duty_cycle) / 100) - 1
// Ex. 70% duty cycle:
// TIM_Pulse = (((7199 + 1) * 70) / 100) - 1 = 5039


TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

}

void msdelay(unsigned int ncount)
{
	unsigned int i,j;
	for(i=0; i<ncount;i++)
		for(j=0; j<0x2AFF;j++);
}



void ADC1_Init()
{
	ADC_InitTypeDef ADC_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = DISABLE;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC1, &ADC_InitStruct);
	ADC_Cmd(ADC1, ENABLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

uint16_t ADC1_Read()
{
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

	return ADC_GetConversionValue(ADC1);
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
	if(TIM_GetITStatus(TIM2,TIM_IT_CC2)==SET)
		{
			if(count==0)
			{
			value1 = TIM_GetCapture2(TIM2);
			count=1;
				TIM_SetCompare2(TIM2, 0);
				TIM_ClearFlag(TIM2,TIM_IT_CC2);
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
				Frequency1=8000000.0/(cap*500);
				if(Frequency1!=0)
					{flag=1;}
				TIM_SetCompare2(TIM2, 0);
				TIM_ClearFlag(TIM2,TIM_IT_CC2);
			}
			
			
		}

void configureKeyPadpins(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	myLED.GPIO_Speed = GPIO_Speed_2MHz; 
	myLED.GPIO_Mode = GPIO_Mode_Out_PP;
	myLED.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;     // Column 1, 2 & 3
	GPIO_Init(GPIOA, &myLED);
	myLED.GPIO_Speed = GPIO_Speed_2MHz; 
	myLED.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	myLED.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;   // Row A, B, C & D
	GPIO_Init (GPIOA, &myLED);
}

void SetColumnsHigh(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_13,1);  // Col-1 = 1
	GPIO_WriteBit(GPIOA, GPIO_Pin_14,1); // Col-2 = 1 
	GPIO_WriteBit(GPIOA, GPIO_Pin_15,1); // Col-3 = 1
	Col_1=1; 
	Col_2=1; 
	Col_3=1;
}

void SetColumnsLow(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_13,0); // Col-l = 0
	GPIO_WriteBit(GPIOA, GPIO_Pin_14,0); // Col-2 = 0
	GPIO_WriteBit(GPIOA, GPIO_Pin_15,0); // Col-3 = 0
	Col_1=0; 
	Col_2=0; 
	Col_3=0;
}

void SetColumn_1(void)
{

	GPIO_WriteBit(GPIOA, GPIO_Pin_13,1); // Col-1 = 1 
	GPIO_WriteBit(GPIOA, GPIO_Pin_14,0); // Col-2 = 0 
	GPIO_WriteBit(GPIOA, GPIO_Pin_15,0); // Col-3 = 0 
	Col_1=1; 
	Col_2=0;
	Col_3=0;
}

void SetColumn_2(void)
{

	GPIO_WriteBit(GPIOA, GPIO_Pin_13,0); // Col-1 = 0 
	GPIO_WriteBit(GPIOA, GPIO_Pin_14,1); // Col-2 = 1 
	GPIO_WriteBit(GPIOA, GPIO_Pin_15,0); // Col-3 = 0 
	Col_1=0; 
	Col_2=1;
	Col_3=0;
}

void SetColumn_3(void)
{

	GPIO_WriteBit(GPIOA, GPIO_Pin_13,0); // Col-1 = 0 
	GPIO_WriteBit(GPIOA, GPIO_Pin_14,0); // Col-2 = 0 
	GPIO_WriteBit(GPIOA, GPIO_Pin_15,1); // Col-3 = 1 
	Col_1=0; 
	Col_2=0;
	Col_3=1;
}

void KeyPad_Scan(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
	{
		lcd16x2_cursor_shift_left();
		if (Col_1==1)
			lcd16x2_puts("1"); 
		if (Col_2==1)
					lcd16x2_puts("2"); 
		if(Col_3==1)
			lcd16x2_puts("3");
	}
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 1)
	{
		lcd16x2_cursor_shift_left();
 
		if(Col_1==1)	
			lcd16x2_puts("4"); 
		if (Col_2==1)
					lcd16x2_puts("5"); 
		if (Col_3==1)
			lcd16x2_puts("6");
	}
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 1)
	{
		lcd16x2_cursor_shift_left();
		if(Col_1==1)
			lcd16x2_puts("7"); 
		if(Col_2==1)
			lcd16x2_puts("8");
		if (Col_3==1)
			lcd16x2_puts("9");
	}
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 1)
	{
		lcd16x2_cursor_shift_left(); 

		if(Col_1==1)
			lcd16x2_puts("*"); 
		if(Col_2==1)	
			lcd16x2_puts("O"); 
		if (Col_3==1)
			lcd16x2_puts("#");
	}
}

void GPIOinit(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
gpioinit.GPIO_Pin = GPIO_Pin_1;
gpioinit.GPIO_Mode = GPIO_Mode_AF_OD;
gpioinit.GPIO_Speed = GPIO_Speed_2MHz;
GPIO_Init(GPIOA, &gpioinit);
}

void pwminit(void)
{
TIM_TimeBaseInitTypeDef timeinit;
TIM_OCInitTypeDef ocinit;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
timeinit.TIM_Prescaler = 10;
timeinit.TIM_Period = 7199;
timeinit.TIM_ClockDivision = TIM_CKD_DIV1;
timeinit.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM2, &timeinit);
TIM_Cmd(TIM2, ENABLE);
ocinit.TIM_OCMode = TIM_OCMode_PWM1;
ocinit.TIM_OutputState = TIM_OutputState_Enable;
ocinit.TIM_OCPolarity = TIM_OCPolarity_High;
ocinit.TIM_Pulse = 3599;
TIM_OC2Init(TIM2, &ocinit);	
TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
}

void msdelay(unsigned int ncount)
{
	unsigned int i,j;
	for(i=0; i<ncount;i++)
		for(j=0; j<0x2AFF;j++);
}