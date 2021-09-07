/*
 * servomotor with button.c
 *
 * Created: 21-08-2021 18:24:54
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>


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
    

    //prescaller set 64
    TCCR1B|=(1<<CS11)|(1<<CS10);
    TCCR1B &=(~(1<<CS12));
    
    DDRD |=(1<<DDD5); //for pd5 and pd4
	DDRA &=(~(1<<DDA1));//for +90
	DDRA &=(~(1<<DDA2));
	

    /* Replace with your application code */
//button for 90 degree +==
//button for -90
    
    while (1)
    {
		if(PINA &(1<<PINA1)){
		for(unsigned int i=0;i<1024;i++){
	    OCR1A=800;
	    _delay_ms(2000);
    }
	}
	else{
	
	if(PINA &(1<<PINA2)){
    
    for(unsigned int i=1023;i>1;i--){
	    OCR1A=300;
	    _delay_ms(2000);
    }
	}
	}
}
}

