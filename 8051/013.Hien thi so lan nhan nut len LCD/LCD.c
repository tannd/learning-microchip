#include <REGX52.H>
#include <stdio.h>
#include <string.h>

sbit sw = P3^5;

sbit RS = P1^0;
sbit RW = P1^1;
sbit EN = P1^2;
char x;
void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}
void delay(unsigned long int t)
	{
		unsigned long int i;
		for (i=0;i<t;i++);
	}
void busy_flag(void)
	{
		P2 = 0xff;
		RS = 0;
		RW = 1;
		do
			{
				EN = 0;
				delay(10);
				EN = 1;
				x = P2;
				x = x&0x80;
			}
		while(x==0x80);
	}
void write_command(unsigned char LCD_command)
	{
		busy_flag();
		P2 = LCD_command;
		RS = 0;
		RW = 0;
		EN = 1;
		delay(50);
		EN = 0;
		delay(50);
	}
void write_data (unsigned char LCD_data)
	{
		busy_flag();
		P2 = LCD_data;
		RS = 1;
		RW = 0;
		EN = 1;
		delay(50);
		EN = 0;
		delay(50);
	}
void write_string(char *s)
	{
		while(*s)
			{
				write_data(*s);
				s++;
			}
	}

void init(void)
	{
		write_command(0x03);//
		write_command(0x38);//hien thi 2 dong
		write_command(0x06);// tro ve dau
		write_command(0x0c);// bo dau nhay
	}
void restart()
{
		write_command(0x01);//xoa man hinh
		delay(1000);
}
void startline1()
{
		write_command(0x80);//vi tro con tro dau dong 1
		delay(1000);
}
void startline2()
{
		write_command(0xc0);//vi tri con tro dau dong 2
		delay(1000);
}
void write_intnum(unsigned long n)       
{         
	if(n!=0)                                             
            {
                   unsigned char a[11];                       
                   int i;                                        
                   for(i=0;n>0;i++)       //tach so           
                        {
                              a[i]=(n%10)+48;      
                              n=n/10;                      
                        }
					a[i]=NULL;	                          
               	    for(i=strlen(a);i>=0;i--)   //gui so          
                	{                                                      
                        write_data(a[i]);                             
           
                	}
            }
   	else write_data('0');
}

void write_realnum(float n)                             
{
            unsigned long a=n/1;               //tach phan nguyen
            unsigned long b=(n-a)*10000;      //tach phan thap phan
            write_intnum(a);                  // gui phan nguyen
            if(b!=0)                          //gui phan thap phan va dau "."
            {
                        write_data('.');                                
                        write_intnum(b);                
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
						delay_ms(30);
						init();
                        count=TL1;
						if (count >99)
						{
							count = 0;
							TL1=0;
	
						}
						write_intnum(count);
						delay_ms(10);

            }
}
