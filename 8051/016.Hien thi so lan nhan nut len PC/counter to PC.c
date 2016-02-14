#include <REGX52.H>
#include <stdio.h>
#include<string.h>  

sbit sw = P3^5;

void delay_ms(unsigned int  ms)
{
 	int i,j;
	for(i=0;i<ms;i++)
	{
	 	for(j=0;j<121;j++);
	}
}

void setup()
{
		 
		 TMOD=0x26;//timer1 che do 2, timer 0 che 2/dem
		 SCON=0x50;
		 TH1=TL1=-3;	//9600
		 TH0=0;
		// TH1=TL1=-6;	//4800
		 TR1=1;
		 TR0=1;
		 sw=1;

}
void sendchar(unsigned char a)                       
{
            SBUF=a;                                
            while(TI==0);                    
            TI=0;                                      
}

void sendstring(char *a)                 
{
            int i,n;                                     
            n=strlen(a);                          
            for(i=0;i<n;i++)                   
            {                                              
                        sendchar(a[i]);
            }         
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

void sendrealnum(float n)                             
{
            unsigned long a=n/1;               //tach phan nguyen
            unsigned long b=(n-a)*10000;      //tach phan thap phan
            sendintnum(a);                  // gui phan nguyen
            if(b!=0)                          //gui phan thap phan va dau "."
            {
                        sendchar('.');                                
                        sendintnum(b);                
            }
}

void main()                                                            
{
			unsigned int count;
		   	setup();
            while(1)                                
            {
                       //sendintnum(10000);
					   //sendchar(13);
					   	count=TL0;
						if (count >99)
						{
							count = 0;
							TL0=0;
	
						}
					   sendintnum(count);
					   delay_ms(500);
					   sendchar(8);
					   //delay_ms(500);
            }
}
