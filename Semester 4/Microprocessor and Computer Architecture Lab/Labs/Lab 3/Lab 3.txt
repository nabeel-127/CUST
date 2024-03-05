////Activity 2
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//int cliflag1 = 1;
//void main()
//{
	//DDRD = (1 << DDRD1);
	//PORTD = (1 << PORTD1);
	//PORTD = (1 << PORTD3);
	//GICR = (1 << INT1);
	//while (1)
	//{
		//if (cliflag1 == 0)
		//{
			//sei();
		//}
		//else
		//{
			//cli();
			//_delay_ms(2000);
			//cliflag1 = 0;
		//}
	//}
//}
//ISR(INT1_vect)
//{
	//PORTD ^= (1 << PORTD1);
	//cliflag1 = 1;
//}

////Activity 3
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util//delay.h>
//int cliflag1 = 1;
//void main()
//{
	//DDRD = (1 << DDRD1) | (1 << DDRD6);
	//PORTD = (1 << PORTD1);
	//PORTD = (1 << PORTD3) | (1 << PORTD2);
	//GICR = (1 << INT1) | (1 << INT0);
	//while (1)
	//{
		//if (cliflag1 == 0)
		//{
			//sei();
		//}
		//else
		//{
			//cli();
			//_delay_ms(2000);
			//cliflag1 = 0;
		//}
	//}
//}
//ISR(INT1_vect)
//{
	//PORTD ^= (1 << PORTD1);
	//cliflag1 = 1;
//}
//ISR(INT0_vect)
//{
	//PORTD ^= (1 << PORTD6);
	//cliflag1 = 1;
//}

//Activity 4
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void main()
{
	DDRB = 0xFF;
	PORTD = (1 << PORTD3);
	GICR = (1 << INT1);
	MCUCR = (1 << ISC10);
	sei();
	while (1)
	{
		_delay_ms(1000);
		PORTB = 0x01;
		for (int i = 1; i <= 8; i++)
		{
			_delay_ms(100);
			PORTB = PORTB << 1;
		}
	}
}
ISR(INT1_vect)
{
	for (int i = 1; i <= 5; i++)
	{
		PORTB = 0xFF;
		_delay_ms(500);
		PORTB = 0x00;
		_delay_ms(500);
	}
}