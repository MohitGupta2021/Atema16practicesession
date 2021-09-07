#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
      // SET MODE OF THE TIMER
      TCCR1A |= (1<<WGM10) | (1<<WGM11);
      TCCR1B |= (1<<WGM12);
      TCCR1B &= ~(1<<WGM13);                   // FAST PWM 10 - BIT
      
      TCCR1A |= (1<<COM1A1);
      TCCR1A &= ~(1<<COM1A0);      // PWM IN NON INVERTING MODE
      
      
      // SET THE PRESCALER FOR THE TIMER FOR SETTING PWM FREQUENCY
      TCCR1B |= (1<<CS10) | (1<<CS11);
      TCCR1B &= ~(1<<CS12);             // PRESCALER = 64
      // FREQ OF PWM = 16MHz / 64 = 250KHz
      
      // CONFIGURE THE OUTPUT COMPARE PIN AS O/P
      DDRD |= (1<<DDD5);
      	   
    while (1) 
    {
        for(int i=0;i<1024;i++)
        {
	        OCR1B = i;
	        _delay_ms(3);
        }
        _delay_ms(2000);
        for(int i=1023;i>=0;i--)
        {
	        OCR1B = i;
	        _delay_ms(3);
        }
        _delay_ms(2000);
        
        
        
	
	}
}

 