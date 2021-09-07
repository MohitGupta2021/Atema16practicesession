/*
 * pushbutton and led.c
 *
 * Created: 11-03-2021 03:25:38
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |=(1<<DDB0);//output
	DDRB &= ~(1<<DDB1);//input
	
    while (1) 
    {
		if(PINB &=(1<<PINB1))
		{
			PORTB |=(1<<PB0);//high
			
    }
	else{
		PORTB &= ~(1<<PB0);//low
		
	}
}
}


