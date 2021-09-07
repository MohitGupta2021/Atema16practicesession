/*
 * GccApplication1.c
 *
 * Created: 19-08-2021 19:08:54
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)

{
	DDRB |=(1<<DDB0);
	DDRC &=(~(1<<DDC0));
	DDRA |=(1<<DDA0);
	DDRD =0x80;
	
	
    /* Replace with your application code */
    while (1) 
    {
		if(PINC &(1<<PINC0))
		{
			PORTB |=(1<<PB0);
			_delay_ms(1000);
			PORTA =0x01;
			_delay_ms(1000);
			PORTD=0x80;
			_delay_ms(1000);
			
    }
	else{
		PORTB &=(~(1<<PB0));
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTA =0x00;
		_delay_ms(1000);
		
	}
}
}

