/*
 * projectfinal.c
 *
 * Created: 5/23/2019 1:34:18 PM
 * Author : Talha
 */ 

#include <avr/io.h>
#include <util/delay.h>

void moveforward();
void moveright();
void moveleft();


int main(void)
{
	
	DDRC = 0b00000000;
	
	DDRD =  0b01000000; //D6 is left
	DDRB =  0b00001000; //B3 is right
	
	//phase correct
	//1024
	
	

	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= (0 << WGM01) | (1 << WGM00);
	// set phase correct PWM Mode

	TCCR0B |= (1 << CS02) |(0 << CS01) | (1 << CS00) | (0 << WGM02) ;
	// set prescaler to 1024 and starts PWM
	
	
	
	
	
	
	
	TCCR2A |= (1 << COM2A1);
	// set none-inverting mode

	TCCR2A |= (0 << WGM21) | (1 << WGM20);
	// set phase correct PWM Mode

	TCCR2B |= (1 << CS21)|(1 << CS22) | (1 << CS20) | (0 << WGM22) ;
	// set prescaler to 1024 and starts PWM
	
	OCR2A = 255; //start from 0
	OCR0A = 255; //set as 0
	


    /* Replace with your application code */
    while (1) 
    {
		
		
		//forward
		if ( ((PINC & 0x01) == 0) && ((PINC & 0x02) == 0) )
		{
			moveforward();
			
		}
		//right
		if ( ((PINC & 0b00000001) == 0) && ((PINC & 0b00000010) == 2) )
		{
			moveright();
			
		}
		
		//left
		 if ( ((PINC & 0b00000001) == 1) && ((PINC & 0b00000010) == 0) )
		{
			moveleft();
			
		}
						
    }
}


void moveforward()
{
	OCR0A = 180; //left //40% speed
	OCR2A = 180; //right 20%
	
	
}
void moveleft()
{
	OCR0A = 0; //left //0 stops it
	OCR2A = 102; //right
		
}
void moveright()
{
	OCR0A = 102; //left // 60% speed
	OCR2A = 0;; //right
	
}


