#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
double dutycycle = 0;
int main()
{
	DDRB = 0b00001000;
	DDRD = 0b01000000;
	
	//0A Clock
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TIMSK0 = (1<<TOIE0);
	OCR0A = 0;
	sei();
	TCCR0B |= (1<<CS00);
	
	//2A Clock
	//TCCR2A = 0b10000011;
	TCCR2A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TIMSK2 = (1<<TOIE2);
	OCR2A = 0;
	sei();
	TCCR2B |= (1<<CS00);
	
	EIMSK = (1 << INT0) | (1 << INT1);
	
	DDRC = 0x00;
	while (1)
	{
		//_delay_ms(1000);
		if (PINC == 0b01000001)
		{
			INT0_vect();
		}
		if (PINC == 0b01000010)
		{
			INT1_vect();
		}

	}
}
ISR(INT0_vect)
{
	OCR0A = 60;
	//_delay_ms(1000);
}
ISR(INT1_vect)
{
	OCR2A = 200;
	//_delay_ms(1000);
}