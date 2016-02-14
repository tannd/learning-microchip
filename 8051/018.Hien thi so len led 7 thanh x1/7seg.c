#include <REGX52.H>
void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}
unsigned char seg7[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void main()
{
	int i;
	while(1)
	{
	 	 for(i=0;i<10;i++)
		 {
		 	P2=seg7[i];
			delay_ms(1000);
		 }
	}
}