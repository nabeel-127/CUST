/*
 * Retry.c
 *
 * Created: 6/1/2019 4:16:35 AM
 * Author : Nabeel
 */ 

#include <avr/io.h>
//#include <util/delay.h>



void forward();
void left();
void right();



int dutycycle = 0;



int main(void)
{
    DDRD =  0b01000000; // OCR0A (Left)
    DDRB =  0b00001000; // OCR2A (Right)
	
	// TIMER0
	
	//Setting "Phase Correct PWM" mode
	TCCR0A = (1 << WGM00);
	
	//Setting "Non-Inverting" mode
	TCCR0A |= (1 << COM0A1);
	
	//Turning clock ON (No Prescaler)
	TCCR0B |= (1 << CS00);
	
	// TIMER2
	
	//Setting "Phase Correct PWM" mode
	TCCR2A = (1 << WGM00);
	
	//Setting "Non-Inverting" mode
	TCCR2A |= (1 << COM0A1);
	
	//Turning clock ON (No Prescaler)
	TCCR2B |= (1 << CS00);
	
	OCR0A = dutycycle;
	OCR2A = dutycycle;
	
    while (1) 
    {	
		if (PIND == 0b01010001 || PIND == 0b00010001)	//Forward
		{
			dutycycle = 150;
			forward();
		}
		else if (PIND == 0b01011110 || PIND == 0b00011110)	//Right Far
		{
			dutycycle = 200;
			right();
		}
		else if (PIND == 0b01011100 || PIND == 0b00011100)	//Right Closer
		{
			dutycycle = 180;
			right();
		}
		else if (PIND == 0b01011000 || PIND == 0b00011000)	//Right Close
		{
			dutycycle = 160;
			right();
		}
		else if (PIND == 0b01001111 || PIND == 0b00001111)	//Left Far
		{
			dutycycle = 200;
			left();
		}
		else if (PIND == 0b01000111 || PIND == 0b00000111)	//Left Closer
		{
			dutycycle = 180;
			left();
		}
		else if (PIND == 0b01000011 || PIND == 0b00000011)	//Left Close
		{
			dutycycle = 160;
			left();
		}
		else
		{
			dutycycle = 51;
			forward();
		}
		
		//if ((PIND4 == 1) && (PIND3 == 0) && (PIND2 == 0) && (PIND1 == 0) && (PIND0 == 1))	//Forward
		//{
			//dutycycle = 180;
			//forward();
		//}
		//if ((PIND4 == 1) && (PIND3 == 1) && (PIND2 == 1) && (PIND1 == 1) && (PIND0 == 0))	//Right Far
		//{
			//dutycycle = 120;
			//right();
		//}
		//if ((PIND4 == 1) && (PIND3 == 1) && (PIND2 == 1) && (PIND1 == 0) && (PIND0 == 0))	//Right Closer
		//{
			//dutycycle = 100;
			//right();
		//}
		//if ((PIND4 == 1) && (PIND3 == 1) && (PIND2 == 0) && (PIND1 == 0) && (PIND0 == 0))	//Right Close
		//{
			//dutycycle = 80;
			//right();
		//}
		//if ((PIND4 == 0) && (PIND3 == 1) && (PIND2 == 1) && (PIND1 == 1) && (PIND0 == 1))	//Left Far
		//{
			//dutycycle = 120;
			//left();
		//}
		//if ((PIND4 == 0) && (PIND3 == 0) && (PIND2 == 1) && (PIND1 == 1) && (PIND0 == 1))	//Left Closer
		//{
			//dutycycle = 100;
			//left();
		//}
		//if ((PIND4 == 0) && (PIND3 == 0) && (PIND2 == 0) && (PIND1 == 1) && (PIND0 == 1))	//Left Close
		//{
			//dutycycle = 80;
			//left();
		//}
    }
}



void forward()
{
	OCR0A = dutycycle; // left
	OCR2A = dutycycle; // right
}



void left()
{
	OCR0A = 0;
	OCR2A = dutycycle;
}



void right()
{
	OCR0A = dutycycle;
	OCR2A = 0;
}