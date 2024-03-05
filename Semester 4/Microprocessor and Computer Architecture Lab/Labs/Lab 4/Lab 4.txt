////Activity 1
//#include <avr/io.h>
//#include <util/delay.h>
//#define BitGet(p, m)((p) & (m))
//#define BitSet(p, m)((p) |= (m))
//#define BitFlip(p, m)((p) ^= (m))
//#define Bit(x)(0x01 << (x))
//void TimerDelay();
//void main()
//{
//DDRA = 0xFF;
//BitSet(PORTA, Bit(0));
//while (1)
//{
//BitFlip(PORTA, Bit(0));
//TimerDelay();
//}
//}
//void TimerDelay()
//{
//TCNT0 = 0x9E;
//TCCR0 = 0x05;
//while (!BitGet(TIFR, Bit(0)))
//{
//TCCR0 = 0x00;
//}
//BitSet(TIFR, Bit(0));
//}

////Activity 2
//#include "avr/io.h"
//void T0Delay();
//void main()
//{
//DDRB = 0xFF;
//while (1)
//{
//PORTB = 0x55;
//T0Delay();
//PORTB = 0xAA;
//T0Delay();
//}
//}
//void T0Delay()
//{
//TCNT0 = 0x20;
//TCCR0 = 0x01;
//while ((TIFR & 0x01) == 0);
//TCCR0 = 0;
//TIFR = 0x01;
//}

////Activity 3
//#include <avr/io.h>
//void T0Delay();
//void main()
//{
	//DDRB = (1 << DDRB4);
	//DDRC = (1 << DDRC6);
	//TCCR0 = (1 << CS00) | (1 << CS02);
	//while (1)
	//{
		//PORTB = (1 << PORTB4);
		//PORTC = (1 << PORTC6);
		//T0Delay();
		//PORTB ^= (1 << PORTB4);
		//PORTC ^= (1 << PORTC6);
		//T0Delay();
	//}
//}
//void T0Delay()
//{
	//TCNT0 = 0x0A;
	//while (TCNT0 != 0xFF);
	//TIFR = (0 << TOV0);
//}

////Activity 4
//#include <avr/interrupt.h>
//void main()
//{
	//DDRB = 0x01;
	//TCCR0 = (1 << WGM01);
	//OCR0 = 100;
	//TIMSK = 1 << OCIE0;
	//sei();
	//TCCR0 |= (1 << CS00);
	//while (1);
//}
//ISR(TIMER0_COMP_vect)
//{
	//static int count = 0;
	//count++;
	//if (count >= 5)
	//{
		//PORTB ^= (1 << PORTB0);
		//count = 0;
		//TCNT0 = 0;
	//}
//}

////Activity 5
//#include <avr/interrupt.h>
//void main()
//{
	//DDRB = (1 << DDRB7);
	//TCCR0 = (1 << WGM01);
	//OCR0 = 200;
	//TIMSK = (1 << OCIE0);
	//sei();
	//TCCR0 |= (1 << CS00);
	//while (1);
//}
//ISR(TIMER0_COMP_vect)
//{
	//static int count = 0;
	//count++;
	//if (count >= 500)
	//{
		//PORTB ^= (1 << PORTB7);
		//count = 0;
		//TCNT0 = 0;
	//}
//}

////Activity 6 (PWM method)
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//double dutycycle = 20;
//int main()
//{
	//DDRB = (1<<DDRB3);
	//TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01);
	//TIMSK = (1<<TOIE0);
	//OCR0 = (dutycycle / 100) * 255;
	//sei();
	//TCCR0 |= (1<<CS00) | (1 << CS02);
//}
//ISR(TIMER0_OVF_vect)
//{
	//OCR0 = (dutycycle / 100) * 255;
//}

//Activity 6 (Non-PWM method)
#include <avr/interrupt.h>
void main()
{
	DDRB = (1 << DDRB7);
	TCCR0 = (1 << WGM01);
	OCR0 = 100;
	TIMSK = 1 << OCIE0;
	sei();
	TCCR0 |= (1 << CS00);
	while (1);
}
ISR(TIMER0_COMP_vect)
{
	static int count = 0;
	count++;
	if (PINB == (1 << PINB7) && count >= 500)
	{
		PORTB ^= (1 << PORTB7);
		count = 0;
		TCNT0 = 0;
	}
	else if (count >= 2000)
	{
		PORTB ^= (1 << PORTB7);
		count = 0;
		TCNT0 = 0;
	}
}
