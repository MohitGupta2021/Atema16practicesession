

#include <avr/io.h>
#include <util/delay.h>

//set pwm mode
//fast 10 bit


int main(void)
{TCCR1A |=(1<<WGM10) |(1<<WGM11);
	TCCR1B &=(~(1<<WGM13));
	TCCR1B |=(1<<WGM12);
	//
	//
	//pwm mode
	//i non inveting pwm mode

	TCCR1A |=(1<<COM1A1);
	TCCR1A &=(~(1<<COM1A0));
	

	//prescaller set 64
	TCCR1B|=(1<<CS11)|(1<<CS10);
	TCCR1B &=(~(1<<CS12));
	
	DDRD |=(1<<DDD5); //for pd5 and pd4

	/* Replace with your application code */

	



	while (1)
	{for(unsigned int i=0;i<1024;i++){
		OCR1A=i;
		_delay_ms(2);
	}
	_delay_ms(2000);
	for(unsigned int i=1024;i>=1;i--){
		OCR1A=i;
		_delay_ms(2);
	}
	_delay_ms(2000);
	}
	

	}

