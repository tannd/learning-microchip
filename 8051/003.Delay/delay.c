#include <REGX51.H>
#define led P0^0
void delay_us(unsigned int us)
{			  
	while(us--)
	{
	}
}

void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}
void main()
{
	while(1)
	{
		delay_ms(1000);
	
	}

}