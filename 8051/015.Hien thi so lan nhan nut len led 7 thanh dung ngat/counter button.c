#include <REGX52.H>
#include<stdio.h>
sbit led1= P1^0;
sbit led2= P1^1;

unsigned char m[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int num,i,l1,l2;
void delay(int time)
{
	while(time--);
}
void sang(void)
{

				int k;
				l1=num/10;
				l2=num%10;
				for(k=0;k<100;k++)
				{
					P2=m[l1];
					led1=1;led2=0;
					delay(100);

					P2=0xff;
					delay(100);

					P2=m[l2];
					led2=1; led1=0;
					delay(100);

					P2=0xff;
					delay(100);
				}
}
void ngat(void) interrupt 0
{
	num++;
}
void main()
{

	EA=1;
	IT0=1;
	IE=0x81;
	while(1)
	{
		 sang();

	}
}