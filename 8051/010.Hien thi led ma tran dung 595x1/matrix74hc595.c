#include <REGX52.H>

sbit SCK = P3^0;
sbit DATA = P3^1;
sbit SCL = P3^2;
//							  1     2	 3	  4    5    6  
unsigned char code mang[] = { 0xFC,0xFC,0x80,0x80,0xFC,0xFC,
						  	  0x83,0xF5,0xF6,0xF5,0x83,
						      0x80,0xFD,0xFB,0xF7,0x80,0xFF,0xff
						  }; //T A N
unsigned char cot[8]   = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};



void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for (j=0;j<=125;j++);	
}

void quet(unsigned char x)
{
	int i,temp;
	for(i=0;i<8;i++)
	{
		temp = x;
		temp = temp&0x80;
		if(temp==0x80) DATA = 1;
		else DATA = 0;
		x*=2;
		SCK = 0;
		SCK = 1;
	}
	SCL = 0;
	SCL = 1;
}

void main()
{
	int j,i,k;
	while(1)
	{
		for(j=0;j<18;j++)
		
			for(k=0;k<10;k++)//tan so quet
			for(i=0;i<8;i++)
			{					
			 P2=cot[i];	 
			 quet(mang[(i+j)%18]);
			 delay(5);
			}
			P2=0;
			delay(100);
	}
}
