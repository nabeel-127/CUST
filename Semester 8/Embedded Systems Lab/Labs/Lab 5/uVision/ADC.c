#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "delay.h"
#include "lcd16x2.h"
#include <stdio.h>

void ADC1_Init(void);
uint16_t ADC1_Read(void);

uint16_t adcValue;
char sAdcValue[5];



void pwminit(void);
void GPIOinit(void);
void msdelay(unsigned int ncount);
GPIO_InitTypeDef gpioinit;
int bright;

int main(void)
{
	int flag= 0;
	
	float voltage;
	
		
	GPIOinit();
	pwminit();
	
	DelayInit();
	lcd16x2_init(LCD16X2_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
	
	lcd16x2_puts("Farakh Ali173096");
	lcd16x2_gotoxy(1,1);
	lcd16x2_puts("ADC = ");
	
	DelayMs(10);
	
	// Initialize ADC
	ADC1_Init();
	
	while (1)
	{
		// Read ADC value
		adcValue = ADC1_Read();
		
		// Convert ADC value to Voltage using formulae
		voltage = (float)adcValue; 	
		
		// Convert Voltage(float) into Voltage(string)
		sprintf(sAdcValue, "%0.1f", voltage);
		
		// Display ADC value to LCD
		lcd16x2_gotoxy(7 ,1);
		lcd16x2_puts(sAdcValue);

		DelayMs(5);
		
		if(voltage <= 3096)
		{
			flag =1;
		}
		
		if(flag ==1 )
		{
		
				for(bright= 3091 ; bright <= 7199; bright += 10)
					{
						TIM2->CCR2 = bright;
					}
				for(bright = 7199 ; bright >= 0; bright -= 3096)
					{
						TIM2->CCR2 = bright;
					}
		}
		}
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
ocinit.TIM_Pulse = 6911;
TIM_OC2Init(TIM2, &ocinit);
	
// Duty cycle calculation equation:
// TIM_Pulse = (((TIM_Period + 1) * duty_cycle) / 100) - 1
// Ex. 96% duty cycle:
// TIM_Pulse = (((7199 + 1) * 96) / 100) - 1 = 6199
	
	
TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

}

void msdelay(unsigned int ncount)
{
	unsigned int i,j;
	for(i=0; i<ncount;i++)
		for(j=0; j<0x2AFF;j++);
}

void ADC1_Init()
{
	// Initialization struct
	ADC_InitTypeDef ADC_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// Step 1: Initialize ADC1
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
	// Select input channel for ADC1
	// ADC1 channel 0 (PA0)
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	// Step 2: Initialize GPIOA (PA0)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

uint16_t ADC1_Read()
{
	// Start ADC conversion
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	// Wait until ADC conversion finished
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

	return ADC_GetConversionValue(ADC1);
}

