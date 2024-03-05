/*
 * Lab_11.c
 *
 * Created: 6/14/2019 10:22:17 AM
 * Author : Nabeel
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0x00;
	DDRB = 0xFF;
    while (1) 
    {
		if ((PINA & 0x80) == 0)
		{
			PORTB = 0x66;
			_delay_ms(10);
			PORTB = 0xCC;
			_delay_ms(10);
			PORTB = 0x99;
			_delay_ms(10);
			PORTB = 0x33;
			_delay_ms(10);
		}
		else
		{
			PORTB = 0x66;
			_delay_ms(100);
			PORTB = 0x33;
			_delay_ms(100);
			PORTB = 0x99;
			_delay_ms(100);
			PORTB = 0xCC;
			_delay_ms(100);
		}
	}
}
