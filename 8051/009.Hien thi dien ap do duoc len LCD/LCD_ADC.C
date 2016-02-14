#include <regx51.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//khai bao LCD
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
char x;

//khai bao ADC
unsigned char n;
sbit INTR_ADC = P3^3;
sbit RD_ADC = P3^4;
sbit WR_ADC = P3^5;

int i;
float volt;


void delay_ms(unsigned int ms)
{
	unsigned int x,y;
	for(x=0;x<ms;x++)
	for(y=0;y<=125;y++);
}

////ham cho LCD
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
//het khai bao cho LCD

void main(void)
 {
 	P2 = 0xFF;
	while(1)
		{
			

			delay30ms();
			init();
			write_command(0x01); //xoa man hinh
			delay(10);
			write_command(0x80);//dua con tro ve dau dong
			write_stri(" Dien Ap: ");
			delay(10);

			delay(2000);
			
		}
 }
