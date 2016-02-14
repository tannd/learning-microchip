#include<at89x52.h>
#define kenh1 P2_0
#define kenh2 P2_1
#define kenh3 P2_2
#define kenh4 P2_3
#define kenh5 P2_4
#define kenh6 P2_5
#define kenh7 P2_6
#define kenh8 P2_7
unsigned char t_on=0,chu_ki=100,pwm1=0;pwm2=0;pwm3=0;pwm4=0,pwm5 =0,pwm6=0,pwm7=0,pwm8=0;
void timer0() interrupt 1	// ham ngat timer 0
{
TR0=0;
t_on++;
if(t_on>chu_ki)t_on=0;
TR0=1;
}
void pwm()
{
kenh1=(pwm1>t_on)? 0:1;	
kenh2=(pwm2>t_on)? 0:1;
kenh3=(pwm3>t_on)? 0:1;
kenh4=(pwm4>t_on)? 0:1;
kenh5=(pwm5>t_on)? 0:1;
kenh6=(pwm6>t_on)? 0:1;
kenh7=(pwm7>t_on)? 0:1;
kenh8=(pwm8>t_on)? 0:1;
}
void main()
{
TMOD=0x02;	//timer 0 mode 2
TH0=155; //timer 0 chay 100uS
TL0=155;
ET0=1;	 //cho phep ngat timer 0
EA=1;	 //cho phep ngat toan cuc
pwm1=80;//gia tri pwm
pwm2=20;
pwm3=40;
pwm4=50;
pwm5=70;
pwm6=80;
pwm7=30;
pwm8=100;
TR0=1;
while(1)
{
pwm();	
}
}