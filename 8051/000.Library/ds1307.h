/* -------------------------------------------------
	Thu vien ds1307
-------------------------------------------------- */

#ifndef _DS1307_
#define _DS1307_
// -------------------------------------------------
/********************** CAC CHUONG TRINH CON CHO DS1307 ********************/
/* Ham doc DS1307 */
unsigned char DS1307_read(unsigned char addr)
{
	unsigned int temp,ret;
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0xD0); 	/* Connect to DS1307 */
	I2C_write(addr); 	/* Request RAM address on DS1307 */
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0XD1); 	/* Connect to DS1307 for Read */
	ret = I2C_read(); 	/* Receive data */
	I2C_stop();
	//**********************************************************
	temp = ret; 							/*BCD to HEX*/
	ret = (((ret/16)*10)+ (temp & 0x0f)); 	/*for Led 7seg*/
	//**********************************************************
	return ret;
}
/* Ham ghi DS1307 */
void DS1307_Write(unsigned char addr,unsigned char dat)
{
	unsigned int temp;
	//**********************************************
	temp = dat ; 						/*HEX to BCD*/
	dat = (((dat/10)*16)|(temp %10)); 	/*for Led 7seg*/
	//**********************************************
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0XD0); 	/* Connect to DS1307 */
	I2C_write(addr); 	/* Request RAM address on DS1307 */
	I2C_write(dat); 	/* Connect to DS1307 for Read */
	I2C_stop();
}
/* lay data tu DS1307 */
void Read_DS1307()
{
	sec   = DS1307_read(SEC);
	min   = DS1307_read(MIN);
	hour  = DS1307_read(HOUR);	
}
/* ghi data tu DS1307 */
void Write_DS1307()
{
	DS1307_Write(SEC,sec);
	DS1307_Write(MIN,min);
	DS1307_Write(HOUR,hour);
}
void Out_1Hz()
{
	I2C_start(); /* Start i2c bus */
	I2C_write(0xD0); /* Connect to DS1307 */
	I2C_write(0x07);   /*vi tri con tro RTC */
	I2C_write(0x10);
	I2C_stop();
}
// -------------------------------------------------
#endif
// ------------------END OF FILE--------------------
// --------------------------------------------------
