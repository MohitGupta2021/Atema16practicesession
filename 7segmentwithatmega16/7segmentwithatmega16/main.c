/*
 * 7segmentwithatmega16.c
 *
 * Created: 11-03-2021 03:12:42
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB=0xFF;
	unsigned char segment[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f},i=0;
    while (1) 
    {for(i=0;i<10;i++){
		PORTB=segment[i];
		_delay_ms(100);
		
    }
}
}

