/*
 * extrenal interrupt.c
 *
 * Created: 20-08-2021 22:26:20
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)

{
	DDRB|=(1<<DDB0)|(1<<DDB1);
	
	sei();
	GICR |=(1<<INT0)|(1<<INT1)|(1<<INT2);
	MCUCR |=(1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);
	MCUCSR|=(1<<ISC2);
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}
ISR(INT0_vect){
	PORTB |=(1<<PB0);
	
	
}
ISR(INT1_vect){
	PORTB &=(~(1<<PB0));
}
ISR(INT2_vect){
	PORTB =(1<<PB1);
}

