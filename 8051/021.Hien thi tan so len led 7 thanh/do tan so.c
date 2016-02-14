#include <REGX52.H>
#include<stdio.h>
sbit led1= P1^0;
sbit led2= P1^1;
sbit led3= P1^2;
sbit led4= P1^3;
unsigned int ms,tan_so;

unsigned char m[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int num,i,nghin,tram,chuc,donvi;
void delay(int time)
{
	while(time--);
}
void sang(void)
{
				int k;
				nghin=num/1000;
				tram=(num%1000)/100;
				chuc=((num%1000)%100)/10;
				donvi=((num%1000)%100)%10;
				for(k=0;k<100;k++)
				{
					P2=m[nghin];
					led1=1; led2=led3=led4=0;
					delay(100);

					P2=0xff;
					delay(100);

					P2=m[tram];
					led2=1; led1=led3=led4=0;
					delay(100);

					P2=0xff;
					delay(100);

					P2=m[chuc];
					led3=1; led1=led2=led4=0;
					delay(100);

					P2=0xff;
					delay(100);

					P2=m[donvi];
					led4=1; led1=led3=led2=0;
					delay(100);
			   	
					P2=0xff;
					delay(100);
				}

}

void ngat0(void) interrupt 0
{
	tan_so++;	
}
void timer0(void) interrupt 1
{
	TF0=0;
	TH0=(65536-50000)>>8;
	TL0=(65535-50000)%256;
	ms++;
}
void main()
{

	
	IE=0x81;  //cho phep ngat toan cuc	
	TMOD = 0x01;
	TR0=1;
	TF0=1;
	EA=1;
	ET0=1;
	IT0=1;

	while(1)
	{
		if(ms>=20)
		{
			ms=0;
		 	num=tan_so;
			tan_so=0;
		}
		 sang();

	}
}