#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>
#define MISO 6
int main()
{
	DDRA = 0xFF;
	DDRB = (1 << MISO);
	SPCR = (1 << SPE);
	while (1)
	{
		SPDR = 'D';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);

		SPDR = 'O';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);

		SPDR = 'G';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);
	}
	
	return 0;
}