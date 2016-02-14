#include <REGX52.H>
#include <stdio.h>
sbit RS = P1^0;
sbit RW = P1^1;
sbit EN = P1^2;
char x;
void delay30ms(void)
	{
		TMOD = 0x10;
		TH1 = 35535/256;
		TL1 = 35535%256;
		TR1 = 1;
		while (!TF1);
		TR1 = TF1=0;
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
		write_command(0x03);
		write_command(0x38);
		write_command(0x06);
		write_command(0x0c);
	}
void main(void)
	{
		delay30ms();
		init();
		
			
				write_command(0x01);
				delay(10);
				write_command(0x80);
				write_string(" DUY TAN ");
				delay(10);
				write_command(0xc0);
				write_string (" KHOA DIEN TU");
			   while(1);
	}