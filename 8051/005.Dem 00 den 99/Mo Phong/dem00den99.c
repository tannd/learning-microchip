#include <REGX52.H>
#include <stdio.h>

unsigned char num,so1,so2,
			  LED[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
char x;

void delay(unsigned int t)
{
	int i,j;
	for(i=0;i<=t;i++)
	for(j=0;j<=125;j++);
}
void led7thanh(num){
	so1=num/10;
	so2=num%10;
	P0=LED[so1];
	P2=LED[so2];
	delay(200);	
}
void main()
{
  
  SCON = 0X52;
  TMOD = 0X20;
  TH1 = TL1 = -3;
  TR1 =1;
  IE = 0x90;
  
  while(1)
  {	
  }
}
void ngat() interrupt 4
{
  unsigned int i;
  lap:
  x=_getkey();
  if(x=='s')
  {	 
  do
  { 
	   for(i=0;i<=20;i++)
	   {  	   
	   	led7thanh(i);
		if (i==20) {led7thanh(0);goto lap;}
	   }
  }while(x!='s');
  }
  else
  {
	   for(i=x;i<=20;i++)
	   {  	   
	   	led7thanh(i);
		if (i==20) {led7thanh(0);goto lap;}
	   }	   
  }
}