/*
 * relay.c
 *
 * Created: 20-08-2021 04:41:18
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)

{ DDRD |=(1<<DDD7);//output relay
	DDRC &=(~(1<<DDC0));
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		if(PINC &(1<<PC0))
		{
			PORTD |=(1<<PD7);
			_delay_ms(1000);
		}
		else{
			PORTD &=(~(1<<PD7));
			_delay_ms(1000);
		}
			
    }
}

