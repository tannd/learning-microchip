/**
  ********************************************************************
  * Filename : PWM.c
  * Author	 : nguyen.duy.tan
  * Date	 : 11/01/2015 (dd/mm/yyyy)         						 
  ********************************************************************
  */
#include <REGX52.H>
/*********************************************************************/
sbit    PWM = P2^0;
sbit    TANG = P1^2;
sbit    GIAM = P1^5;
/*********************************************************************/
unsigned char dem=0,tocdo=50;
bit TANG1=1,TANG0=1,GIAM0=1,GIAM1=1;
/*********************************************************************/
void timer0(void) interrupt 1
{
		TR0 = 0;
		TF0 = 0;
		dem++;
		if(dem > 100){ dem = 0;}
		if(dem<tocdo){ PWM = 1;}else {PWM = 0;}
		TR0 = 1;
}
/*********************************************************************/
void phimnhan()// xu ly phim bam
{
	TANG0=TANG1;TANG1=TANG;
	if((TANG0==1)&&(TANG1==0))
	tocdo=tocdo+10;
	if(tocdo==110)tocdo=100;
	
	GIAM0=GIAM1;GIAM1=GIAM;
	if((GIAM0==1)&&(GIAM1==0))
	tocdo=tocdo-10;
	if(tocdo==-10)tocdo=0;
}
/*********************************************************************/
void init()		// khoi tao
{
	TMOD = 0x02;
	IE = 0x82;
	TH0=TL0=-100; // tao tan so 0.1 ms
	TR0 = 1;
	PWM=0;
}
/*********************************************************************/
void main(void)
{
	init(); // khoi tao truoc khi chay
	while(1) // lap vo tan
	{
		phimnhan(); // goi ham xu ly phim bam
	}
}
/**************************** END ***********************************/