#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int dutycycle = 0;
void left();
void right();
void forward();
void main()
{
	DDRB = 0b00001000;	//Right Motor
	DDRD = 0b01000000;	//Left Motor
	DDRC = 0x00;
	
	//0A Clock
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TCCR0B = (1<<CS02) | (1<<CS01) | (1<<CS00) | (1 << WGM02);
	
	//2A Clock
	TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2A1);
	TCCR2B = (1<<CS02) | (1<<CS01) | (1<<CS00) | (1 << WGM22);
	
	OCR0A = 255;
	OCR2A = 255;
	
	while (1)
	{
		//_delay_ms(1000);
		if (PINC == 0b01010001)	//Forward
		{
			dutycycle = 150;
			void forward();
		}
		if (PINC == 0b01011110)	//Right Far
		{
			dutycycle = 200;
			void right();
		}
		if (PINC == 0b01011100)	//Right Closer
		{
			dutycycle = 180;
			void right();
		}
		if (PINC == 0b01011000)	//Right Close
		{
			dutycycle = 160;
			void right();
		}
		if (PINC == 0b01001111)	//Left Far
		{
			dutycycle = 200;
			void left();
		}
		if (PINC == 0b01000111)	//Left Closer
		{
			dutycycle = 180;
			void left();
		}
		if (PINC == 0b01000011)	//Left Close
		{
			dutycycle = 160;
			void left();
		}
	}
}
void left()
{
	OCR0A = dutycycle;
}
void right()
{
	OCR2A = dutycycle;
}
void forward()
{
	OCR0A = dutycycle;
	OCR2A = dutycycle;
}