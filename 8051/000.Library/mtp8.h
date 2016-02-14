/*
******************************************************************************
  File getkey();
******************************************************************************
*/
	
#ifndef __MTP8_H
#define __MTP8_H
										 // 0	1	2	3	4	5	6
static unsigned char code KEYS_PAD[16][7]={'a','b','c','d','e','f','g',// 0
										   'h','i','j','k','l','m','n', // 1
										   'o','p','q','r','s','t','u',	// 2
										   'v','w','x','y','z','{','}',	// 3
										   '@','@','@','@','7','8','9',	// 4
										   '@','@','@','@','4','5','6',	// 5
										   '@','@','@','@','1','2','3',	// 6
										    20,'@','@','@','0',8,10,	// 7
										   'A','B','C','D','E','F','G',	// 8
										   'H','I','J','K','L','M','N', // 9
										   'O','P','Q','R','S','T','U',	// 10
										   'V','W','X','Y','Z','[',']',	// 11
										   '@','@','@','@','&','*','(',	// 12
										   '@','@','@','@','$','%','^',	// 13
										   '@','@','@','@','!','@','#',	// 14
										   20,'@','@','@',')',8,10	// 15
										   };
//unsigned char caplock=0;
// -----------------------------------------------------------------------------------------------------
bit caplock=0;
unsigned char getkey()
{
	unsigned int hang,cot;
	unsigned char kt=0;
	P0=0xFF;	// out
	P2=0x00;	//in
	delay_us(2);

	if((P0&0xff)!=0xff)										// Kiem tra xem co phim bat ky nao duoc bam hay khong?
	{
		delay_us(100);												// Chong nhieu
		if((P0&0xff)!=0xff)									// Neu dung có phim duoc bam: Bat dau qua trinh quet phim
		{
			for(cot=0;cot<7;cot++)									// Quet theo cot
			{
				P2=~(0x01<<cot);							// Lan luot keo cac cot xuong muc logic 0
				delay_ms(1);
				for(hang=0;hang<8;hang++)								// Kiem tra cac hang
				{
						if((P0&(0x01<<hang))==0)				// Neu hang nao co muc logic 0
						{
							while((P0&0xff)!=0xff);		// Cho den khi nut bam duoc tha ra
							if(caplock==1)
							{
							 kt= KEYS_PAD[hang+8][cot];		// Tra ve ma phim da duoc bam
							}
							else kt= KEYS_PAD[hang][cot];		// Tra ve ma phim da duoc bam
						}
				}
			}
		}
	}
	return kt;														// Neu khong co phim nao duoc nhan: Tra ve gia tri 0
}
// ------------------------------------------------------------------------										      
#endif

// ------------------END OF FILE--------------------
// -------------------------------------------------
