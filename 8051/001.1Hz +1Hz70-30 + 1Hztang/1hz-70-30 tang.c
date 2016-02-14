// Write by Huu Quang
#include <REGX52.H>
#define tan_so 20
char millisec;
char do_rong_xung;
void delay_ms(unsigned int timer)
{
 	int i,j;
	for(i=0;i<timer;i++)
		for(j=0;j<121;j++);
}
/*
void ISR_1000ms(void) interrupt 1 	 // ham ngat timer 0
{
	TF0 = 0;//xoa co tran
	TH0 =0xE2;	 // nap du lieu vao thanh ghi timer
	TL0 =0x0A;
	TR0=1;
    P2_1=~P2_1;
}
*/
int main()
{
 	
	TMOD=0x01;//timer 0 che do 16 bit
	TR0=1;    //cho phep timer 0 hoat dong
	TH0=(0xFFFF-50000)>>8;
	TL0=(0xFFFF-50000)|0xFF;
	
	while(1)
	{
	 	
		while(TF0!=0) 
		{
		 	millisec++;
			TF0=0;
			TH0 =(0xFFFF-50000)>>8;	 // nap du lieu vao thanh ghi timer
			TL0 =(0xFFFF-50000);
			
			if(millisec<=do_rong_xung)
			{
				P2_0=1; 	
			}
			else if(millisec<=tan_so)
			{
			 	P2_0=0;
			}
			else millisec=0;
		}
		if(P2_1==0)
		{
		 	while(P2_2==0);
			delay_ms(100);
			do_rong_xung+=1;
			if(do_rong_xung>=tan_so)
				do_rong_xung=1;
		}
	}
}