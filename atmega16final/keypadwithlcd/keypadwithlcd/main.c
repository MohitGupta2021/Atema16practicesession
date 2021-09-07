/*
 * keypadwithlcd.c
 *
 * Created: 20-08-2021 10:59:43
 * Author : porwa
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define lcd_data PORTD
#define ctrl PORTB
#define RS PB0
#define RW PB1
#define EN PB2

#define pad PORTA
#define C1 PA0
#define C2 PA1
#define C3 PA2
#define R1 PA3
#define R2 PA4
#define R3 PA5
#define R4 PA6

void lcd_data(unsigned char data){
	PORTD=data;
	RS=1;
	RW=0;
	EN=1;
	_delay_ms(1000);
	EN=0;
	
}
void lcd_cmd(unsigned char command){
	PORTD=command;
	RS=0;
	RW=0;
	EN=1;
	_delay_ms(1000);
	EN=0;
	
}
void lcd_string(const unsigned char *str,unsigned char num){
	unsigned char i';
	for(i=0;i<num;i++){
		lcd_data(str[i]);
}
void lcd_initialise(){
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
}

	







int main(void)
{ DDRD=0xFF;//lcd as output
	DDRA=0x0F;//1=output c1,c2,c3
	DDRB=0x07;//rs rw en as output
	pad=0xf0;
	lcd_initialise();
	lcd_data("hi",2);
	lcd_cmd(0xc0);
	while(1)
	{
		
	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

