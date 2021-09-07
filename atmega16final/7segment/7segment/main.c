/*
 * 7segment.c
 *
 * Created: 19-08-2021 18:24:42
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	DDRA=0xFF;
	
	unsigned char segment[10]={0x3F,0x06,0x58,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F},i;
	
    /* Replace with your application code */
    while (1) 
    { 
		for(i=0;i<=10;i++)
		{
		
		PORTD=segment[i];
		_delay_ms(1000);
		
    }
	PORTA=0xF9;
	_delay_ms(1000);
	PORTA=0xE4;
	_delay_ms(1000);
		PORTA=0xB0;
		_delay_ms(1000);
		PORTA=0x99;
		_delay_ms(1000);
		
	
}
}

