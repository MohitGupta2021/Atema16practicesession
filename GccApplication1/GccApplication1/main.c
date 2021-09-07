
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    DDRA=0XFF;
	
    while (1) 
    {
		PORTA=0XFF;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
    }
}

