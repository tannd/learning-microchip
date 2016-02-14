#include <REGX52.H>
#include <stdio.h>
void delay_ms(unsigned int  ms)
{
 	int i,j;
	for(i=0;i<ms;i++)
	{
	 	for(j=0;j<121;j++);
	}
}

int c;
void main()
{
 	SCON=0x52;
	TMOD=0x20;
	TH1=TL1=-3;	//9600
	TR1=1;
//	while(1)
	{
			
			/*
			while(!TI);
			TI=0;
			SBUF=65;
			*/
			for (c=32;c<127;c++)
			{
			 
				putchar(c);
				 if(c%10==0 && c!=0) putchar(0x0D);
				putchar(32);
		    	delay_ms(10);
			}
			printf("hien thi: %2.2f",4.5);
			while(1);
	}
}