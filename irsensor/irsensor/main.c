/*
 * irsensor.c
 *
 * Created: 08-02-2021 11:40:03
 * Author : porwa
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA=0x00;
	DDRC=0xFF;
    while (1) 
    {
		int x=PORTA&0x01;
		if(x == 0x01)
		{
			PORTC=0xF0;
			}
			else if(x == 0x00)
			{
				
				PORTC=0x0f;
			}
			
    }
}

