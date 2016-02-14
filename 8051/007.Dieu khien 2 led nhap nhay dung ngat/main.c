#include <REGX52.H>

sbit Led_vang=P1^0;
sbit Led_do=P1^2;
void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}
void timer_0(void) interrupt 1
{
	int i;
	Led_vang=0;
 	for(i=0;i<=20;i++)
	{
		Led_do=~Led_do;
		delay_ms(100);	
	}
}
void main()
{
	//set interrupt
	EA=1;//enable interrupt gobal
	IT0=1;
	IE=0x81;
	while(1)
	{
		 Led_do=0;
		 Led_vang =~Led_vang;
		 delay_ms(100);

	}
}
