#include <REGX52.H>

sbit sw=P3^5;
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;

unsigned char donvi,chuc,tram,nghin;

unsigned int i,s;

unsigned char m[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay(int time)
{
	while(time--);
}

void display(unsigned int num)
{
				nghin=num/1000;
				tram=(num%1000)/100;
				chuc=((num%1000)%100)/10;
				donvi=((num%1000)%100)%10;

				for(i=0;i<50;i++)
				{
					P2=m[chuc];
					led1=1; led2=0;
					delay(100);

					P2=0xff;
					delay(100);

					P2=m[donvi];
					led2=1;led1=0;
					delay(100);

					P2=0xff;
					delay(100);
				}
	
}
void main(void)                                     
{
			unsigned int count;
            TMOD=0x60;
            TH1=0x00;              
           	sw=1;                    
            TR1=1;                       

            while(1)                     
            {
                        count=TL1;
						if (count >99)
						{
							count = 0;
							TL1=0;
	
						}
						display(count);
            }
}
