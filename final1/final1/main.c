
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{ DDRB |=(1<<DDB0);
    /* Replace with your application code */
    while (1) 
    {
		PORTB |=(1<<PB0);
		_delay_ms(1000);
		PORTB &=(~(1<<PB0));
		_delay_ms(1000);
    }
}

