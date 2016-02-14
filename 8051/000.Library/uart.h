/*
******************************************************************************
  File getkey();
******************************************************************************
*/
	
#ifndef __UART_H
#define __UART_H
#include <stdio.h>
#include <string.h>
// ------------------------------------------------------------------------	
void uart_int()
{
		TMOD=0x21;//timer 1 che do 2, timer 0 che do 1
		SCON=0x50;// port noi tiep che do 1, RE=TI=1;
		TH1=TL1=-3;// toc do baud la 9600
		TH0=0xFC;//0xFC; 
		TL0=0x17;//0x17;// dat gia tri khoi tao cho timer 0
		TR0=1;// cho phep timer 0 chay
		TR1=1;// cho phep timer 1 chay
		IE=0x92;// cho ngat port noi tiep, ngat tu timer 0
		IP=0;// muc uu tien ngat bang nhau

}
void uart_write_char(unsigned char a)                       
{
            SBUF=a;                                
            while(TI==0);                    
            TI=0;                                      
}

void uart_write_string(char *a)                 
{
            int i,n;                                     
            n=strlen(a);                          
            for(i=0;i<n;i++)                   
            {                                              
                        uart_write_char(a[i]);
            }         
}
void uart_write_int(unsigned long n)       
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
                        uart_write_char(a[i]);                             
           
                	}
            }
   	else uart_write_char('0');
}
// ------------------------------------------------------------------------										      
#endif

// ------------------END OF FILE--------------------
// -------------------------------------------------
