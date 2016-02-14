#include <REGX52.H>
sbit xung1= P2^0;
sbit xung2= P2^1;

void ngatT0(void) interrupt 1
{
 TR0=0;
 TH0=-10000/256;
 TL0=-10000%256;
 TR0=1;
 xung2=~xung2;
}
void ngatT1(void) interrupt 3
{
	xung1=~xung1;
}
void main(void)
{
	TMOD = 0x21;
	TH1= TL1=-25;
	TR1=1;

	IE=0x8A;
	IP=0;
	TF0=1;
	while(1);
}