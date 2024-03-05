/*
 * project.c
 *
 * Created: 5/19/2019 10:03:05 PM
 * Author : Talha
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

void moveforward();
void moveright();
void moveleft();

int main(void)
{
  //using Register C as input for the sensor
	DDRC = 0x00;  //make pins as input
  
	DDRD = 0b01000000;
	PORTD = 0x00;
	DDRB = 0b00000010;
	PORTB = 0x00;
	
	//Using 0A and 1A
	TCCR0A = 0b10000011; //right motor
	TCCR0B = 0b00001101;
	TCCR1A = 0b10000011; //left motor
	TCCR1B = 0b00001101;
	
	TCNT0 = 0;  
	TCNT1 = 0;
	TIMSK0 = 0b00000000;
	TIMSK1 = 0b00000000;
	
	OCR0A = 255;
	OCR1A = 255;  

    while (1) 
    {
		if (((PINC & 0x01) == 0) && ((PINC & 0x02) == 0))
		{
			moveforward();
		}
		if (((PINC & 0x01) == 0) && ((PINC & 0x02) == 1))
		{
			moveright();
		}
		if (((PINC & 0x01) == 1) && ((PINC & 0x02) == 0))
		{
			moveleft();
		}

		//if((PINC0 == 1) && (PINC1 == 1) && (PINC2 == 0) && (PINC3 == 1) && (PINC4 == 1))
		//{
		  //moveforward();
		//}
		//
		//turnRight
		//if((PINC0 == 1) && (PINC1 == 1) && (PINC2 == 1) && (PINC3 == 0) && (PINC4 == 1))
		//{
		  //moveright();
		//}
		//if((PINC0 == 1) && (PINC1 == 1) && (PINC2 == 1) && (PINC3 == 1) && (PINC4 == 0))
		//{
		  //moveright();
		//}
		//if((PINC0 == 1) && (PINC1 == 1) && (PINC2 == 0) && (PINC3 == 0) && (PINC4 == 0))
		//{
		  //moveright();
		//}
		//
		//
		//turnLeft
		//if((PINC0 == 1) && (PINC1 == 0) && (PINC2 == 1) && (PINC3 == 1) && (PINC4 == 1))
		//{
		  //moveleft();
		//}
		//if((PINC0 == 0) && (PINC1 == 1) && (PINC2 == 1) && (PINC3 == 1) && (PINC4 == 1))
		//{
		  //moveleft();
		//}
		//if((PINC0 == 0) && (PINC1 == 0) && (PINC2 == 0) && (PINC3 == 1) && (PINC4 == 1))
		//{
		  //moveleft();
		//}
		
	}
}

void moveright()
{
	OCR0A = 155;
	OCR1A = 0; 
}

void moveleft()
{
	OCR0A = 0;
	OCR1A = 155;
}

void moveforward()
{
	OCR0A = 155; 
	OCR1A = 155;
}