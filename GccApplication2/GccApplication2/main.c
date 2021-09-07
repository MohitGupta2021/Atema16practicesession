/*
 * GccApplication2.c
 *
 * Created: 08-02-2021 10:17:55
 * Author : porwa
 */ 

#include <avr/io.h>
#include<util/delay.h>


int main(void)

{
	DDRA=0xFF;
	DDRB=0x00;
    /* Replace with your application code */
    while (1) 
    {
		int switch_1=PORTB=0b00000001;
		if(switch_1==1)
		{
			PORTA=0b00000001;
		}
		else
		{
		 PORTA=0b00000000;
		_delay_ms(5000);
		}
		
    }
}

