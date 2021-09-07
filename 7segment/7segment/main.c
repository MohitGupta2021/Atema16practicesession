/*
 * 7segment.c
 *
 * Created: 08-02-2021 10:38:55
 * Author : porwa
 */ 

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    DDRA=0xff;
    while (1) 
    {
		PORTA=0x7E;
		_delay_ms(1000);
		PORTA=0x6b;
		_delay_ms(1000);
		PORTA=0x0C;
		_delay_ms(1000);
		PORTA=0x4C;
		_delay_ms(1000);
		PORTA=0xE8;
		_delay_ms(1000);
		PORTA=0x4A;
		_delay_ms(1000);
		PORTA=0x1A;
		_delay_ms(1000);
		PORTA=0xEB;
		_delay_ms(1000);	
    }
}

