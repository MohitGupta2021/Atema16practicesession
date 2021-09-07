/*
 * bluetooth withatmega16.c
 *
 * Created: 12-03-2021 07:40:08
 * Author : porwa
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>


uint8_t data=0,rfid[15];

int main()
{
	// ENABLE THE GLOBAL INTERRUPT ENABLE BIT
	sei();
	
	// ENABLE THE TRANSMISSION & RECEPTION IN USART
	UCSRB |= (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
	
	// SET DATA SIZE FOR COMMUNICATION
	UCSRC |= (1<<UCSZ0) | (1<<UCSZ1);
	// SET THE BAUD RATE
	UCSRA |= (1<<U2X);
	UBRRL = 207;
	UBRRH = 0;
	DDRB |= (1<<DDB0);

	while(1)
	{
		if(data == 'a')
		{
			PORTB |= (1<<PB0);
		}
		if(data == 'b')
		{
			PORTB &= ~(1<<PB0);
		}
	}
}


// IMPLEMENT THE INTERRUPT HANDLER
ISR(USART_RXC_vect)
{
	data= UDR;
	
	
}



