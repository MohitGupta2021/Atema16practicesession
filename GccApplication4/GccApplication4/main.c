
#include <avr/io.h>
#include <util/delay.h>
#define lcd PORTB
#define rs PB0
#define rw PB1
#define en PB2

#include <avr/interrupt.h>
#include <stdlib.h>
#define F_CPU 1000000UL

void lcd_cmd(unsigned char com);
void lcd_data(unsigned char data);
void lcd_string(unsigned char  *str);

static volatile int pulse=0;
static volatile int echo_pin=0;

	
int main(void)
	{
		
		DDRB=0xFF;
		DDRD=0xFB;
		_delay_ms(50);
		GICR|=(1<<INT0);
		MCUCR|=(1<<ISC00);
		int16_t COUNTA=0;
		char SHOWA [16];
		
		lcd_cmd(0x02);
		lcd_cmd(0x28);
		lcd_cmd(0x0C);
		lcd_cmd(0x06);
		sei();
		while(1)
		{
			PORTD|=(1<<PIND0);
			_delay_ms(15);
			PORTD &=~(1<<PIND0);
			_delay_ms(15);
			
			COUNTA=pulse/58;
			
			lcd_cmd(0x80);
			lcd_string("ultrasonic sensor");
			lcd_cmd(0xC0);
			lcd_string("distance");
			itoa(COUNTA,SHOWA,10);
			lcd_string(SHOWA);
			lcd_string("cm");
			
			
			
			
		}
		
	}
	
	
ISR(INT0_vect)
{
	
	if(echo_pin==1)
	{
		
		TCCR1B=0;
		pulse=TCNT1;
		TCNT1=0;
		echo_pin=0;
	}
	if(echo_pin==0)
	{
		
		TCCR1B|=(1<<CS10);
		echo_pin=1;
		
	}
}


void lcd_cmd(unsigned char com)
{
	char cmd1;
	cmd1=(com&(0xF0));
	lcd=cmd1;
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
	
	cmd1=((com<<4)&(0xF0));
	lcd=cmd1;
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
}
void lcd_data(unsigned char data)
{
	unsigned char data1;
	data1=(data&(0xF0));
	lcd=data1;
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
	
	data1=((data<<4)&(0xF0));
	lcd=data1;
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
	
}
void lcd_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='/0')
	{
		
		lcd_data(str[i]);
		i++;
	}
	
	
}




