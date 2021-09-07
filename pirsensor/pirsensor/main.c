

#include <avr/io.h>


int main(void)
{
	DDRA= 0x00;//input
	DDRC= 0xff;// output
    /* Replace with your application code */
    while (1) 
	
    {
		int x= PINA & 0b00000001;
		if(x == 1){
			PORTC=0x0f;
			
    }
	else if(x == 0b00000000)
	{
		PORTC=0xf0;
	}
}
}

