#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>
#define MOSI 5
#define SCK 7
int main()
{
	DDRB = (1 << MOSI) | (1 << SCK);
	DDRA = 0xFF;
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	while (1)
	{
		SPDR = 'C';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);

		SPDR = 'A';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);

		SPDR = 'T';
		while (!(SPSR & (1 << SPIF)));
		PORTA = SPDR;
		_delay_ms(5000);
	}
	return 0;
}