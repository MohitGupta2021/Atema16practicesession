#include <avr/io.h>
#include <util/delay.h>

void lcd_data(unsigned char data)
{
	PORTD = data;
	PORTB |= (1<<PB0); // RS = 1;
	PORTB &= (~(1<<PB1)); // RW = 0
	PORTB |= (1<<PB2);   // EN =1
	_delay_ms(10);     // 10MS
	PORTB &= (~(1<<PB2));  // EN =0;
}
void lcd_cmd(unsigned char command)
{
	PORTD = command;
	PORTB &= (~(1<<PB0)); // rs = 0;
	PORTB &= (~(1<<PB1));  // rw =0;
	PORTB |= (1<<PB2);   // en =1;
	_delay_ms(10);    // 10ms
	PORTB &= (~(1<<PB2)); // en =0;
}
void lcd_string(const unsigned char *str,unsigned char length)
{
	char i=0;
	for(i=0;i<length;i++)
	{
		lcd_data(str[i]);
	}
}
void lcd_initialise()
{
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
}


int main(void)
{
   DDRD = 0xFF; // //PORTD AS O/P
   
   DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2); // PB0,PB1,PB2 AS O/P
     

	lcd_initialise();	
    while (1) 
    {
	   lcd_cmd(0x80);
	   lcd_string("EMBEDDED",8);
	   lcd_cmd(0xC0);
	   lcd_string("SYSTEMS",7);
	}
}
