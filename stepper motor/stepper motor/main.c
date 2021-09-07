/*
 * stepper motor.c
 *
 * Created: 12-03-2021 12:16:00
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA=0xF0;
	int period =50;
	
    while (1) 
    {
		for(int i=0;i<50;i++)
		{
			PORTA=0x09;//00001001
			_delay_ms(period);
			PORTA=0x08;//00000011
			_delay_ms(period);
			PORTA=0x0C;
			_delay_ms(period);
			PORTA=0x04;//00000100
			_delay_ms(period);
			PORTA=0x06;//00000110
			_delay_ms(period);
			PORTA=0x02;//00000010;
			_delay_ms(period);
			PORTA=0x03;//00000011
			_delay_ms(period);
			PORTA=0x01;//00000011
			_delay_ms(period);
			
		}
		PORTA=0x09;
		_delay_ms(period);
		_delay_ms(1000);
	for(int i; i<50;i++)
	{
		PORTA=0x01;
		_delay_ms(period);
		PORTA=0x03;
		_delay_ms(period);
		PORTA=0x02;
		_delay_ms(period);
			PORTA=0x06;
			_delay_ms(period);
			PORTA=0x04;
			_delay_ms(period);
			PORTA=0x0C;
			_delay_ms(period);
	PORTA=0x08;
	_delay_ms(period);
	PORTA=0x09;
	_delay_ms(period);
	}
	PORTA=0x09;
	_delay_ms(period);
	_delay_ms(1000);
	
	}
    }


