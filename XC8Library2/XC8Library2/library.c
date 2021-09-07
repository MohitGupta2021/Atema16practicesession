/*
 * library.c
 *
 * Created: 2/8/2021 9:15:04 AM
 *  Author: porwa
 */ 

#include <xc.h>
#include<avr/io.h>

#include<util/delay.h>

int main(void){
	DDRC=0b11111111;
	while(1){
		PORTC=0b11111111;
	_delay_ms(1000);
	PORTC=0b00000000;
	_delay_ms(1000);
	
	}
}