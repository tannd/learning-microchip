#include <REGX52.H>
sbit led1 = P3^0;
sbit led2 = P3^1;
void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}
void delay_us(int time)
{
	while(time--);
}
unsigned char seg7[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void sang(int n)
{
	int c,dv,i;
	c=n/10;
	dv=n%10;
	for(i=0;i<50;i++)
{
		P2=seg7[c];
		led1=1;led2=0;
		delay_us(100);

		P2=0xff;
		delay_us(100);

		P2=seg7[dv];
		led2=1;led1=0;
		delay_us(100);

		P2=0xff;
		delay_us(100);
}

}


void main()
{
	int a;
	while(1)
	{
	 	 for(a=0;a<99;a++)
		 {
				sang(a);
		 }
	}
}