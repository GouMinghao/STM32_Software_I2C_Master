//programmed by Minghao Gou and Yuqiu Huang at Shanghai Jiao Tong University
//the function int main() is an example for how to use this library
//this example is about to use adxl345, the famous accelemeter.



#include "stm32f10x.h"
#include "I2C.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "stdio.h"
#include "main.h"




int main()
{
	Sys_Init();
	while (1)
	{
		ADXL_Measure();
		ADXL_Calculate();
		Led_ON();//to show the transmission
		USART1_SendCharSequence(str);
		USART_SendData(USART1, '\t');
		USART1_SendCharSequence(str1);
		USART_SendData(USART1, '\t');
		USART1_SendCharSequence(str2);
		Led_OFF();
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
		USART_SendData(USART1, '\n');
		//Delay_ms(1);
	}
}


void Sys_Init(void)
{

	Init_Led();// Initilize the led
	USART1_Config();// Config the usart1 port
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
	Led_ON();//to show the transmission
	USART_SendData(USART1, 'a');//Shwo that the program begins.
	Led_OFF();
	DelayInit();
	I2C_Initi();
	I2C_Initi1();
	I2C_Initi2();
	Init_ADXL345();//We must init adxl345 before init I2C bus
	Init_ADXL3451();
	Init_ADXL3452();
}

void ADXL_Measure(void)
{
	//Read the data from the three accelemeters
	ax1l = SingleRead(ADXLADDR, REG_DATA_X_LOW);
	ax1h = SingleRead(ADXLADDR, REG_DATA_X_HIGH);
	ay1l = SingleRead(ADXLADDR, REG_DATA_Y_LOW);
	ay1h = SingleRead(ADXLADDR, REG_DATA_Y_HIGH);
	az1l = SingleRead(ADXLADDR, REG_DATA_Z_LOW);
	az1h = SingleRead(ADXLADDR, REG_DATA_Z_HIGH);
	ax2l = SingleRead1(ADXLADDR, REG_DATA_X_LOW);
	ax2h = SingleRead1(ADXLADDR, REG_DATA_X_HIGH);
	ay2l = SingleRead1(ADXLADDR, REG_DATA_Y_LOW);
	ay2h = SingleRead1(ADXLADDR, REG_DATA_Y_HIGH);
	az2l = SingleRead1(ADXLADDR, REG_DATA_Z_LOW);
	az2h = SingleRead1(ADXLADDR, REG_DATA_Z_HIGH);
	ax3l = SingleRead2(ADXLADDR, REG_DATA_X_LOW);
	ax3h = SingleRead2(ADXLADDR, REG_DATA_X_HIGH);
	ay3l = SingleRead2(ADXLADDR, REG_DATA_Y_LOW);
	ay3h = SingleRead2(ADXLADDR, REG_DATA_Y_HIGH);
	az3l = SingleRead2(ADXLADDR, REG_DATA_Z_LOW);
	az3h = SingleRead2(ADXLADDR, REG_DATA_Z_HIGH);
}
void ADXL_Calculate(void)
{
	//to put the data into high positions
	ax1h <<= 8;
	ay1h <<= 8;
	az1h <<= 8;
	ax2h <<= 8;
	ay2h <<= 8;
	az2h <<= 8;
	ax3h <<= 8;
	ay3h <<= 8;
	az3h <<= 8;
	//The unit of the result is g
	ax1 = (ax1h + ax1l) / (double)256;
	ay1 = (ay1h + ay1l) / (double)256;
	az1 = (az1h + az1l) / (double)256;
	ax2 = (ax2h + ax2l) / (double)256;
	ay2 = (ay2h + ay2l) / (double)256;
	az2 = (az2h + az2l) / (double)256;
	ax3 = (ax3h + ax3l) / (double)256;
	ay3 = (ay3h + ay3l) / (double)256;
	az3 = (az3h + az3l) / (double)256;
	//Print the data via usart1 port
	sprintf(str, "Ax1:%4.2f\tAy1:%4.2f\tAz1:%4.2f ", ax1, ay1, az1);
	sprintf(str1, "Ax2:%4.2f\tAy2:%4.2f\tAz2:%4.2f ", ax2, ay2, az2);
	sprintf(str2, "Ax3:%4.2f\tAy3:%4.2f\tAz3:%4.2f ", ax3, ay3, az3);
}
