

#include <avr/io.h>
#include <util/delay.h>

//set pwm mode
//fast 10 bit
sei();

int main(void)
{
TCCR1A |=(1<<WGM10) |(1<<WGM11);
TCCR1B &=(~(1<<WGM13));
TCCR1B |=(1<<WGM12);
//
//
//pwm mode
//i non inveting pwm mode

TCCR1A |=(1<<COM1A1);
TCCR1A &=(~(1<<COM1A0));
TCCR1A |=(1<<COM1B1);
TCCR1A &=(~(1<<COM1B0));

//prescaller set 64
TCCR1B |=(1<<CS11)|(1<<CS10);
TCCR1B &=(~(1<<CS12));
DDRD |=(1<<DDD5)|(1<<DDD4); //for pd5 and pd4

/* Replace with your application code */

//adc
//enable gei

//enable adc interrupt
ADCSRA |=(1<<ADIE);
//set reference to no avcc and input
//set data alingment in data register
ADMUX=0x00;
ADCSRA |=(1<<ADEN)|(1<<ADATE);
//set frequnce
ADCSRA|=(1<<ADPS2);
ADCSRA &=((~(1<<ADPS0))&(~(1<<ADPS1)));
//start convertion
ADCSRA |=(1<<ADSC);



while (1)
{

}
}
ISR(ADC_vect){
	OCR1A=ADC;
	_delay_ms(2);
}
