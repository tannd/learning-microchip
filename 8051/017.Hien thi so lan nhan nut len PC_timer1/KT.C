#include <REGX52.H>
#include <stdio.h>
#include<string.h> 

unsigned int num; 

void delay_ms(unsigned int  ms)
{
 	int i,j;
	for(i=0;i<ms;i++)
	{
	 	for(j=0;j<121;j++);
	}
}

void sendchar(unsigned char a)                       
{
            SBUF=a; //chuyen ky tu a SBUF                               
            while(TI==0); //cho truyen xong                   
            TI=0;                                      
}

void sendintnum(unsigned long n)       
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
                        sendchar(a[i]);                             
           
                	}
            }
   	else sendchar('0');
}
void ngat(void) interrupt 0	//ngat timer 0
{
	num++;
	sendchar(8); //xoa
	sendchar(8);
	sendintnum(num);//truyen so lan bam
}
void main()

{
		 //EA=1;//cho phep ngat toan cuc
		 IT0=1;//
		 IE=0x81;// 1 0 0 0 0 0 0 1
		 TMOD=0x22;//timer1 che do 2, timer 0 che 2
		 SCON=0x50;//
		 TH1=TL1=-3;	//9600
		 TR1=1;//chay timer 1
		 TR0=1;// chay timer 0
		 sendintnum(0);//in so 0
		 while(1);

}