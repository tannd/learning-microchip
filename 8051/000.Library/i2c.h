/* -------------------------------------------------
	Thu vien I2C
-------------------------------------------------- */

#ifndef _I2C_
#define _I2C_
// -------------------------------------------------
/* Ham khoi dong I2C */
void I2C_start(void)
{
	SCL = 1; SCL = 0;
	SDA = 1; SCL = 1;
	delay(2);
	SDA = 0; delay(2);
	SCL = 0; delay(2);
}
/* Ham het thuc I2C */
void I2C_stop(void)
{
	SCL = 1; SCL = 0;
	SDA = 0; delay(2);
	SCL = 1; delay(2);
	SDA = 1;
}
/* Ham ghi I2C */
bit I2C_write(unsigned char dat)
{
	unsigned char i;
	for (i=0;i<8;i++)
	{
		SDA = (dat & 0x80) ? 1:0;
		SCL=1;SCL=0;
		dat<<=1;
	}
	SCL = 1; delay(2);
	SCL = 0;
	return dat;
}
/* Ham doc I2C */
unsigned char I2C_read(void)
{
	bit rd_bit;
	unsigned char i, dat;
	dat = 0x00;
	for(i=0;i<8;i++) 		/* For loop read data 1 byte */
	{
		delay(2);
		SCL = 1; delay(2); 	/* Set SCL */
		rd_bit = SDA; 		/* Keep for check acknowledge */
		dat = dat<<1;
		dat = dat | rd_bit; /* Keep bit data in dat */
		SCL = 0; 			/* Clear SCL */
	}
	return dat;
}
// -------------------------------------------------
#endif
// ------------------END OF FILE--------------------
// --------------------------------------------------
