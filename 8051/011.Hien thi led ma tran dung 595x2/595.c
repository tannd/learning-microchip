#include <REGX52.H>

sbit SCK1   = P2^0;
sbit DATA1  = P2^1;
sbit SCL1   = P2^2;

sbit SCK2   = P2^3;
sbit DATA2  = P2^4;
sbit SCL2   = P2^5;
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

void quethang(unsigned char num)
{
	int i,temp;
	for(i=0;i<8;i++)
	{
		temp = num;
		temp = temp&0x80;
		if(temp==0x80) DATA1 = 1;
		else DATA1 = 0;
		num=num<<1;
		SCK1 = 0;
		SCK1 = 1;
	}
	SCL1 = 0;
	SCL1 = 1;
}

 void quetcot(unsigned char num)
{
	int i,temp;
	for(i=0;i<8;i++)
	{
		temp = num;
		temp = temp&0x80;
		if(temp==0x80) DATA2 = 1;
		else DATA2 = 0;
		num=num<<1;
		SCK2 = 0;
		SCK2 = 1;
	}
	SCL2 = 0;
	SCL2 = 1;
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
			 quetcot(cot[i]);
			 quethang(mang[(i+j)%18]);
			 delay(5);
			}
			quetcot(0x00);
			delay(100);
	}
}
