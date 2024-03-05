#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
double dutycycle = 0;
int main()
{
	//DDRB = (1<<DDRB3);
	DDRB = 0b00001000;
	DDRD = 0b01000000;
	
	//0A Clock
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TIMSK0 = (1<<TOIE0);
	OCR0A = (dutycycle / 100) * 255;
	sei();
	TCCR0B |= (1<<CS00);
	
	//2A Clock
	//TCCR2A = 0b10000011;
	TCCR2A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TIMSK2 = (1<<TOIE2);
	OCR2A = (dutycycle / 100) * 255;
	sei();
	TCCR2B |= (1<<CS00);
	
	while(1)
	{
		_delay_ms(100);
		
	}
}
ISR(TIMER0_OVF_vect)
{
	OCR0A = 60;
}
ISR(TIMER2_OVF_vect)
{
	OCR2A = 200;
}