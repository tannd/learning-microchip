#include<regx52.h>
sbit F=P2^0;
int dem;
void main()
	 {
	 	TMOD=0x01;
	 	TH0=(65536-50000)/256;
		TL0=(65536-50000)%256;
		TR0=1;
		while(1)
			{	
				TH0=(65536-50000)/256;
				TL0=(65536-50000)%256;
				TR0=1;
				while(!TF0);
				TF0=0;
				TR0=0;
				dem++;
				if(dem==14)
				{
					F=0;
				}
				else
				if(dem==20)
				{
					F=~F;
					dem=0;
					
				}
			}
	 }