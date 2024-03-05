#include "stm32f10x.h" 
#include "stm32f10x_rcc.h" 
#include "stm32f10x_gpio.h" 
#include "delay.h" 
#include "lcd16x2.h"

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

int main(void)
{
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
}


void configureKeyPadpins(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//GPIO Configuration for Columns

	myLED.GPIO_Speed = GPIO_Speed_2MHz; 
	myLED.GPIO_Mode = GPIO_Mode_Out_PP;
	myLED.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;     // Column 1, 2 & 3

	
	GPIO_Init(GPIOA, &myLED);
	
	//GPIO Configuration for Rows
	
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