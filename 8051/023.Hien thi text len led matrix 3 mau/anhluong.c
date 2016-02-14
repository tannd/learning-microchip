#include <REG51.H>
#include <string.h>
void delay(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++);
}
unsigned char code mahang[]={
//	 1	  2 	3	4	 5	  6	   7	8
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,//SPACE-32
	0xFF,0xFF,0xA0,0xFF,0xFF,0xFF,//!    33
	0xFF,0xFF,0xF8,0xF4,0xFF,0xFF,//"    34
	0xEB,0x80,0xEB,0x80,0xEB,0xFF,//#    35
	0xDB,0xD5,0x80,0xD5,0xED,0xFF,//$    36
	0xD8,0xEA,0x94,0xAB,0x8D,0xFF,//%    37
	0xC9,0xB6,0xA9,0xDF,0xAF,0xFF,//&    38
	0xFF,0xFF,0xF8,0xF4,0xFF,0xFF,//'    39
	0xFF,0xE3,0xDD,0xBE,0xFF,0xFF,//(    40
	0xFF,0xBE,0xDD,0xE3,0xFF,0xFF,//)    41
	0xD5,0xE3,0x80,0xE3,0xD5,0xFF,//*    42
	0xF7,0xF7,0xC1,0xF7,0xF7,0xFF,//+    43
	0xFF,0xA7,0xC7,0xFF,0xFF,0xFF,//,    44
	0xF7,0xF7,0xF7,0xF7,0xF7,0xFF,//-    45
	0xFF,0x9F,0x9F,0xFF,0xFF,0xFF,//x    46
	0xFF,0xC9,0xC9,0xFF,0xFF,0xFF,// /   47
	0xC1,0xAE,0xB6,0xBA,0xC1,0xFF,//0    48		
	0xFF,0xBD,0x80,0xBF,0xFF,0xFF,//1    49
	0x8D,0xB6,0xB6,0xB6,0xB9,0xFF,//2    50
	0xDD,0xBE,0xB6,0xB6,0xC9,0xFF,//3    51
	0xE7,0xEB,0xED,0x80,0xEF,0xFF,//4    52
	0xD8,0xBA,0xBA,0xBA,0xC6,0xFF,//5    53
	0xC3,0xB5,0xB6,0xB6,0xCF,0xFF,//6    54
	0xFE,0x8E,0xF6,0xFA,0xFC,0xFF,//7    55
	0xC9,0xB6,0xB6,0xB6,0xC9,0xFF,//8    56
	0xF9,0xB6,0xB6,0xD6,0xE1,0xFF,//9    57
	0xFF,0xC9,0xC9,0xFF,0xFF,0xFF,//:    58
	0xFF,0xA4,0xC4,0xFF,0xFF,0xFF,//;    59
	0xF7,0xEB,0xDD,0xBE,0xFF,0xFF,//<    60
	0xEB,0xEB,0xEB,0xEB,0xEB,0xFF,//=    61
	0xFF,0xBE,0xDD,0xEB,0xF7,0xFF,//>    62
	0xFD,0xFE,0xAE,0xF6,0xF9,0xFF,//?    63
	0xCD,0xB6,0x8E,0xBE,0xC1,0xFF,//@    64	
	0x83,0xF5,0xF6,0xF5,0x83,0xFF,//A    65
	0xBE,0x80,0xB6,0xB6,0xC9,0xFF,//B    66
	0xC1,0xBE,0xBE,0xBE,0xDD,0xFF,//C    67
	0xBE,0x80,0xBE,0xBE,0xC1,0xFF,//D    68
	0x80,0xB6,0xB6,0xB6,0xBE,0xFF,//E    69
	0x80,0xF6,0xF6,0xFE,0xFE,0xFF,//F    70
	0xC1,0xBE,0xB6,0xB6,0xC5,0xFF,//G    71
	0x80,0xF7,0xF7,0xF7,0x80,0xFF,//H	 72
	0xFF,0xBE,0x80,0xBE,0xFF,0xFF,//I	 73
	0xDF,0xBF,0xBE,0xC0,0xFE,0xFF,//J	 74
	0x80,0xF7,0xEB,0xDD,0xBE,0xFF,//K    75
	0x80,0xBF,0xBF,0xBF,0xFF,0xFF,//L    76
	0x80,0xFD,0xF3,0xFD,0x80,0xFF,//M    77
	0x80,0xFD,0xFB,0xF7,0x80,0xFF,//N    78
	0xC1,0xBE,0xBE,0xBE,0xC1,0xFF,//O    79
	0x80,0xF6,0xF6,0xF6,0xF9,0xFF,//P    80
	0xC1,0xBE,0xAE,0xDE,0xA1,0xFF,//Q    81
	0x80,0xF6,0xE6,0xD6,0xB9,0xFF,//R    82
	0xD9,0xB6,0xB6,0xB6,0xCD,0xFF,//S    83 
	0xFE,0xFE,0x80,0xFE,0xFE,0xFF,//T    84
	0xC0,0xBF,0xBF,0xBF,0xC0,0xFF,//U    85
	0xE0,0xDF,0xBF,0xDF,0xE0,0xFF,//V    86
	0xC0,0xBF,0xCF,0xBF,0xC0,0xFF,//W    87
	0x9C,0xEB,0xF7,0xEB,0x9C,0xFF,//X    88
	0xFC,0xFB,0x87,0xFB,0xFC,0xFF,//Y    89
	0x9E,0xAE,0xB6,0xBA,0xBC,0xFF,//Z    90
	0xFF,0x80,0xBE,0xBE,0xFF,0xFF,//[    91
	0xFD,0xFB,0xF7,0xEF,0xDF,0xFF,//\    92
	0xFF,0xBE,0xBE,0x80,0xFF,0xFF,//]    93
	0xFB,0xFD,0xFE,0xFD,0xFB,0xFF,//^    94
	0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,//_    95
	0xFF,0xFF,0xF8,0xF4,0xFF,0xFF,//'    96
	0xDF,0xAB,0xAB,0xAB,0xC7,0xFF,//a    97
	0x80,0xC7,0xBB,0xBB,0xC7,0xFF,//b	 98
	0xFF,0xC7,0xBB,0xBB,0xBB,0xFF,//c	 99
	0xC7,0xBB,0xBB,0xC7,0x80,0xFF,//d	 100
	0xC7,0xAB,0xAB,0xAB,0xF7,0xFF,//e    101
	0xF7,0x81,0xF6,0xF6,0xFD,0xFF,//f	 102
	0xF7,0xAB,0xAB,0xAB,0xC3,0xFF,//g    103
	0x80,0xF7,0xFB,0xFB,0x87,0xFF,//h    104
	0xFF,0xBB,0x82,0xBF,0xFF,0xFF,//i    105
	0xDF,0xBF,0xBB,0xC2,0xFF,0xFF,//j    106
	0xFF,0x80,0xEF,0xD7,0xBB,0xFF,//k    107
	0xFF,0xBE,0x80,0xBF,0xFF,0xFF,//l    108
	0x83,0xFB,0x87,0xFB,0x87,0xFF,//m    109
	0x83,0xF7,0xFB,0xFB,0x87,0xFF,//n    110
	0xC7,0xBB,0xBB,0xBB,0xC7,0xFF,//o    111
	0x83,0xEB,0xEB,0xEB,0xF7,0xFF,//p    112
	0xF7,0xEB,0xEB,0xEB,0x83,0xFF,//q    113
	0x83,0xF7,0xFB,0xFB,0xF7,0xFF,//r    114
	0xB7,0xAB,0xAB,0xAB,0xDB,0xFF,//s    115
	0xFF,0xFB,0xC0,0xBB,0xBB,0xFF,//t    116
	0xC3,0xBF,0xBF,0xDF,0x83,0xFF,//u    117
	0xE3,0xDF,0xBF,0xDF,0xE3,0xFF,//v    118
	0xC3,0xBF,0xCF,0xBF,0xC3,0xFF,//w    119
	0xBB,0xD7,0xEF,0xD7,0xBB,0xFF,//x    120
	0xF3,0xAF,0xAF,0xAF,0xC3,0xFF,//y    121
	0xBB,0x9B,0xAB,0xB3,0xBB,0xFF,//z    122
	0xFB,0xE1,0xE0,0xE1,0xFB,0xFF//^    123
	};
unsigned char code macotd[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned  int l,m,n,t,k,j,i;
unsigned char *xau=" Blog's Tannd";
unsigned char hienthi[100];
void hienchudo(unsigned int c)
{
	  	k=c*6-32*6;
		hienthi[0]=0xff;
		for(i=0;i<6;i++)
			{
	  			hienthi[i+1]=mahang[k+i];
	   		}  
		hienthi[7]=0xff;
		  				for(i=0;i<200;i++)
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								P1=hienthi[n];
								//P3=hienthi[n];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					
}
void hienchuxanh(unsigned int c)
{
	  	k=c*6-32*6;
		hienthi[0]=0xff;
		for(i=0;i<6;i++)
			{
	  			hienthi[i+1]=mahang[k+i];
	   		}  
		hienthi[7]=0xff;
		  				for(i=0;i<200;i++)
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								//P1=hienthi[n];
								P3=hienthi[n];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					
}void hienchuvang(unsigned int c)
{
	  	k=c*6-32*6;
		hienthi[0]=0xff;
		for(i=0;i<6;i++)
			{
	  			hienthi[i+1]=mahang[k+i];
	   		}  
		hienthi[7]=0xff;
		  				for(i=0;i<200;i++)
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								P1=hienthi[n];
								P3=hienthi[n];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					
}
void main()
{

  	l=strlen(xau)*6+8;
	for(i=0;i<8;i++) hienthi[i]=0xff;
	for(i=0;i<strlen(xau);i++)
	{
	 n=0;
	  k=*(xau+i)*6-32*6;
	  for(j=k;j<k+6;j++)
	  {
	  	m=8+i*6+n;
	  	hienthi[8+i*6+n]=mahang[k+n];
		n++;
	   }  
	}
	for(i=m+1;i<m+8;i++) hienthi[i]=0xff; 
	while(1)
	{
		 for(j=48;j<59;j++)
		{
			hienchudo(j);
		}
		for(j=48;j<59;j++)
		{
			hienchuxanh(j);
		}for(j=48;j<59;j++)
		{
			hienchuvang(j);
		}


		for(j=65;j<92;j++)
		{
			hienchudo(j);
		}
		for(j=65;j<92;j++)
		{
			hienchuxanh(j);
		}
		for(j=65;j<92;j++)
		{
			hienchuvang(j);
		}
	
	for(i=0;i<3;i++)
	{
	    	k=0;
			for(t=0;t<l;t++)
				{
					for(j=1;j<100;j++)//thoi gian nhin thay ky tu
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								//P1=hienthi[n+k];
								P3=hienthi[n+k];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					k++;
				}
	}
	
	 for(i=0;i<3;i++)
	{
	    	k=0;
			for(t=0;t<l;t++)
				{
					for(j=1;j<100;j++)//thoi gian nhin thay ky tu
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								//P1=hienthi[n+k];
								P3=hienthi[n+k];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					k++;
				}
	}
	for(i=0;i<3;i++)
	{
	    	k=0;
			for(t=0;t<l;t++)
				{
					for(j=1;j<100;j++)//thoi gian nhin thay ky tu
						for(n=0;n<8;n++)
							{ 
								P2=macotd[n];
								P1=hienthi[n+k];
								//P3=hienthi[n+k];
								delay(20);	// delay mo
							}
					P1=0xff;   //	
					delay(500); //	delay tat
					k++;
				}
	} 
	 }
}