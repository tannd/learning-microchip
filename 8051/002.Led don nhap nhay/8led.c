#include <REGX51.H>
unsigned int i,j;
void delay(unsigned int ms)
{
  for(i=0;i<=ms;i++);
}
void sang_thuan1()
{
  //unsigned char sang_thuan1[]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
   unsigned int x=1;
  for(j=0;j<8;j++)
	{

	  P2=x;
	  x=x<<1|1;
	  delay(10000);
	}
}
void sang_thuan2()
{
  unsigned char sang_thuan2[]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
  for(j=0;j<9;j++)
	{
	  P2=~sang_thuan2[j];
	  delay(9000);
	}
}
void sang_nghich1()
{
  unsigned char sang_nghich1[]={0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};
  for(j=0;j<9;j++)
	{
	  P2=sang_nghich1[j];
	  delay(9000);
	}
}
void sang_nghich2()
{
  unsigned char sang_nghich2[]={0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};
  for(j=0;j<9;j++)
	{
	  P2=~sang_nghich2[j];
	  delay(9000);
	}
}
void mot_led_duoi_thuan1()
{
  P2=0x01;delay(9000);
  for(j=0;j<9;j++)
	{
	  P2=P2<<1;
	  delay(9000);
	}
}
void mot_led_duoi_thuan2()
{
  P2=0x80;delay(9000);
  for(j=0;j<9;j++)
	{
	  P2=P2>>1;
	  delay(9000);
	}
}
void hai_led_duoi_nhau1()
{
  P2=0x03;delay(9000);
  for(j=0;j<9;j++)
	{
	  P2=P2<<1;
	  delay(9000);
	}
}
void hai_led_duoi_nhau2()
{

  P2=0xc0; delay(9000);
  for(j=0;j<9;j++)
	{
	  P2=P2>>1;
	  delay(9000);
	}
}
void nhap_nhay_5_lan()
{
  for(j=0;j<5;j++)
	 {
	  delay(9000);
	  P2=0x00;
	  delay(9000);
	  P2=0xff;
	  delay(9000);
	 }
}
void quet_luu_sang1()
{
  unsigned char quet_luu_sang1[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,
                                 0x81,0x82,0x84,0x88,0x90,0xa0,0xc0,
								 0xc1,0xc2,0xc4,0xc8,0xd0,0xe0,
								  0xe1,0xe2,0xe4,0xe8,0xf0,
								  0xf1,0xf2,0xf4,0xf8,
								  0xf9,0xfa,0xfc,
								  0xfd,0xfe,0xff    };
  for(j=0;j<36;j++)
  {
  P2=quet_luu_sang1[j];
  delay(9000);
  }
}
void dich_bit()
{
  P2=0x07;delay(9000);
  for(j=0;j<9;j++)
  {
  P2=P2<<1; delay(9000);
  }
}
void chuyen_nhanh()
{
  for(j=0;j<10;j++)
  {
    P2=0x55; delay(9000);
	P2=0xaa; delay(9000);
  }
}
void giua_chay_ra()
{
  unsigned char giua_chay_ra[]={0x00,0x18,0x24,0x42,0x81};
  for(j=0;j<5;j++)
	{
	  P2=giua_chay_ra[j];
	  delay(9000);
	}
}
void giua_chay_ra_luu()
{
   unsigned char giua_chay_ra_luu[]={0x00,0x18,0x24,0x42,0x81,0x99,0xa5,0xc3,0xdb,0xe7,0xff};
   for(j=0;j<11;j++)
	{
	  P2=giua_chay_ra_luu[j];
	  delay(9000);
	 }
}
void hai_dau_chay_vao()
{
  unsigned char hai_dau_chay_vao[]={0x00,0x81,0x42,0x24,0x18};
  for(j=0;j<5;j++)
	{
	  P2=hai_dau_chay_vao[j];
	  delay(9000);
	 }
}
void hai_dau_chay_vao_luu()
{
  unsigned char hai_dau_chay_vao_luu[]={0x00,0x81,0x42,0x24,0x18,0x99,0x5a,0x3c,0xbd,0x7e,0xff};
  for(j=0;j<11;j++)
	{
	  P2=hai_dau_chay_vao_luu[j];
	  delay(9000);
	 }
}
void main()
{
  while(1)
  {
	    sang_thuan1();
	    sang_thuan2();
  		sang_nghich1();
		sang_nghich2();
	    nhap_nhay_5_lan();
		mot_led_duoi_thuan1();
		mot_led_duoi_thuan2();
		hai_led_duoi_nhau1();
		hai_led_duoi_nhau2();
		quet_luu_sang1();
		dich_bit();
		chuyen_nhanh();
		giua_chay_ra();
		giua_chay_ra_luu();
		hai_dau_chay_vao();
		hai_dau_chay_vao_luu();

  }
}
