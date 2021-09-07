/*
 * prj1.c
 *
 * Created: 11-03-2021 01:26:17
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    	DDRB=0xFF;
		
	/* Replace with your application code */
    while (1) 
    {
		PORTB |=(1<<PB0);
		_delay_ms(1000);
		PORTB &= ~(1<<PB0);
		_delay_ms(1000);
		
	
		
    }
}

