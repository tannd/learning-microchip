#include <REGX52.H>
#include<stdio.h>
#include<math.h>
sbit led1= P1^0;
sbit led2= P1^1;
sbit led3= P1^2;
sbit led4= P1^3;
unsigned char m[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned char donvi,chuc,tram,nghin;

int num;
void delay(int time)
{
	while(time--);
}

void sang(unsigned int num)
	{ 
			   	int i;
				//num=9876;
				nghin=num/1000;
				tram=(num%1000)/100;
				chuc=((num%1000)%100)/10;
				donvi=((num%1000)%100)%10;
				for(i=0;i<50;i++)
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
void main()
{
	while(1)
	{
		int n;
		for(n=0;n<9999;n++)
		{
		sang(n);
		}
	}
}