/*
 * rgb.c
 *
 * Created: 08-02-2021 10:31:54
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xff;
    while (1) 
    {
		PORTA=0x01;
		_delay_ms(1000);
		PORTA=0x02;
		_delay_ms(1000);
		PORTA=0x04;
		_delay_ms(1000);
		
    }
}

