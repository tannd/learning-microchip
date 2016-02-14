void Out_595(unsigned char num1,unsigned char num2)
{
    char i;
    unsigned int data;
    data = ((unsigned int)num1<<8)|num2; //gop 2 byte num1 va num2 gan cho data (16bit)  
                                         //ket qua data = 0xnum1num2                         
    Enable = 1;          //cam xuat du lieu ra khi chua chuyen doi xong
    for(i = 0;i<16;i++)  
    {
        if(data & 0x8000)//truyen bit co trong so cao truoc
            Data = 1;
        else
            Data = 0;    
        Shcp = 1;      //xung nhip          
        Shcp =0;        
        data =data<<1; //dich tra 1 bit
    }
    Stcp = 1;         //chot du lieu
    Stcp = 0;
    Enable = 0;       //cho phep xuat du lieu ra
}