#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"











//PWM
void pwminit(void);
void GPIOinit(void);
void msdelay(unsigned int ncount);
GPIO_InitTypeDef gpioinit;

int bright;

int main(void)
{
	GPIOinit();
	pwminit();
	
	while(1)
	{
//		for(bright= 0 ; bright <= 7199; bright += 10)
//			{
//				TIM2->CCR2 = bright;
//			}
//		for(bright = 7199 ; bright >= 0; bright -= 10)
//			{
//				TIM2->CCR2 = bright;
//			}
	
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
ocinit.TIM_Pulse = 3599;
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