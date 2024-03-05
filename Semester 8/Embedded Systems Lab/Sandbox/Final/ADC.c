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



int main (void)
{
	
	float voltage;
	DelayInit();
	lcd16x2_init(LCD16X2_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF);
	
	lcd16x2_puts("Voltage = ");
	lcd16x2_gotoxy(3,2);
	
	DelayMs(10);
	
	ADC1_Init();
	while(1)
		{
			adcValue = ADC1_Read();
			voltage  = (float)adcValue/4095 *3.3;
			sprintf(sAdcValue, "% f v", voltage);
			
				
			lcd16x2_gotoxy(3,2);
			lcd16x2_puts(sAdcValue);
				
			DelayMs(5);
		}
	
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
	
		ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
}

uint16_t ADC1_Read()
{
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	
	return ADC_GetConversionValue(ADC1);
}