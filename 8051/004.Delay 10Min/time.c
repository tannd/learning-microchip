#include <REGX52.H>
sbit led = P2^0;

void delay_ms(unsigned int ms)
{
	unsigned int i;
	for (i=0;i<ms;i++)
	{
		TH0=0xFC;
		TL0=0x17; //or 17,gia tri ban dau cho timer
		TR0=1; // cho phep timer hoat dong
		while (!TF0); //cho co tran
		TF0=0; //xóa co tran
		TR0=0; // dung timer
	}
}
void delay_sec(unsigned int sec)
{
	unsigned int j;
	for (j=0;j<sec;j++)
	{
		 delay_ms(1000);
	}
}
void delay_min(unsigned int min)
{
	unsigned int k;
	for (k=0;k<min;k++)
	{
		 delay_sec(60);
	}
}
void main (void)
{
	TMOD = 0x01;//timer 0 che do 1 16 bit
	while(1)
	{
		led = 0;
		delay_sec(10);
		led =1;
		delay_sec(10);
	}
}