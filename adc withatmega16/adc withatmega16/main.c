/*
 * adc withatmega16.c
 *
 * Created: 11-03-2021 23:01:08
 * Author : porwa
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

PORTD=0XFF;

#define lcd PORTC
#define rs PD0
#define rw PD1
#define en PD2
//void lcd_init();
void lcd_cmd(unsigned char com);
void lcd_data(unsigned char data);
void lcd_string(unsigned char *str);
//------------------------------------------------------------------------

void lcd_cmd(unsigned char com)
{
	//for command rs=0,rw=0,en=1,en=0
	char cmd1;
	cmd1=(com&(0xF0));//upper 4 bit data
	lcd=cmd1;
	lcd&=~(1<<rs);//rs=0
	lcd&=~(1<<rw);//rw=0
	lcd|=(1<<en);//en=1
	_delay_ms(1);
	lcd&=~(1<<en);


	cmd1=((com<<4)&(0xF0));//upper 4 bit data
	lcd=cmd1;
	lcd&=~(1<<rs);//rs=0
	lcd&=~(1<<rw);//rw=0
	lcd|=(1<<en);//en=1
	_delay_ms(1);
	lcd&=~(1<<en);
}
void lcd_data(unsigned char data)
{
	unsigned char data1;
	data1=(data&(0xF0));// upper 4 bit
	lcd=data1;
	lcd|=(1<<rs); //rs=1
	lcd&=~(1<<rw);//rw=0
	lcd|=(1<<en);//en=1
	
	_delay_ms(1);
	lcd&=~(1<<en);//en=0

	data1=((data<<4)&(0xF0));//lower 4 bit data
	lcd=data1;
	lcd|=(1<<rs);//rs=1
	lcd&=~(1<<rw);//rw=0
	lcd|=(1<<en);//en=1
	_delay_ms(1);
	lcd&=~(1<<en);

}
//--------------------------------------------------------------
void lcd_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		lcd_data(str[i]);
		i++;
	}
}


int main(void)
{
	sei();
	TCCR1A |=(1<<WGM10)| (1<<WGM11);//set mode of the timer
	TCCR1B |=(1<<WGM12);
	TCCR1B &= ~(1<<WGM13); //fast pwm 10 bit
	TCCR1A|=(1<<COM1A1);
	TCCR1A &=~(1<<COM1A0);//pwm in non inveting mode
	TCCR1B |=(1<<CS10) |(1<<CS11); //set the [re scaler for the timer
	TCCR1B &= ~(1<<CS12);
	DDRD|=(1<<DDD5);
	ADMUX=0x00;
	ADCSRA |=(1<<ADPS2)|(1<<ADIE)|(1<<ADEN)|(1<<ADATE);
	ADCSRA &= (~(1<<ADPS1)) & (~(1<<ADPS0));
	ADCSRA |=(1<<ADSC);
	
	DDRC=0xFF;
	
	lcd_cmd(0x02);//home location
	lcd_cmd(0x28);//2x16 lcd 4bit mode
	lcd_cmd(0x0C);//dispy on cursor blink
	lcd_cmd(0x06);//increament
	
    /* Replace with your application code */
    while (1) 
    {
		
		lcd_cmd(0x80);
		lcd_data(ADC);
		lcd_cmd(0xc0);
		lcd_string("the world");
	}
    
}
ISR(ADC_vect)
{
	
	OCR1A=ADC;
	
}

