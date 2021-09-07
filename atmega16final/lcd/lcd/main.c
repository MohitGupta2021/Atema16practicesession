

#include <avr/io.h>
#include <util/delay.h>

void lcd_data(unsigned char data)
{
	
	PORTD=data;
	PORTB |=(1<<PB0);//rs=1
	PORTB &=(~(1<<PB1));//rw=0
	PORTB |=(1<<PB2);//en=1
	_delay_ms(10);
	PORTB &=(~(1<<PB2));//en=0
	
	
}

void lcd_cmd(unsigned char command)
{
	
	PORTD=command;
	PORTB &=(~(1<<PB0));//rs=0
	PORTB &=(~(1<<PB1));//rw=0
	PORTB |=(1<<PB2);//en=1
	_delay_ms(10);
	PORTB &=(~(1<<PB2));//en=0
	
	
}


void lcd_string(const unsigned char *str,unsigned char length)
{
	
	char i=0;
	for(i=0;i<length;i++)
	{
		lcd_data(str[i]);
	}
	
}
void lcd_initialise(){
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x01); 
}

int main(void)
{
	DDRD=0xFF;
	//pa0=1
	DDRA &=(~(1<<DDA0));
	DDRB |=(1<<DDB0)|(1<<DDB1)|(1<<DDB2);
	lcd_initialise();
	/* Replace with your application code */
	while (1)
	
	{
		lcd_cmd(0x80);
		lcd_string("embedded",8);
		lcd_cmd(0xC0);
		lcd_string("system",7);
		button();
		
	}
}
void button(){
	if(PINA &(1<<PINA0))
	{
		lcd_cmd(0x80);
		lcd_string("button",6);
		lcd_cmd(0xC0);
		lcd_string("pressed",7);
	}
	else{
		lcd_cmd(0x80);
		lcd_string("no",6);
		lcd_cmd(0xC0);
		lcd_string("pressed",7);
		
	}
}