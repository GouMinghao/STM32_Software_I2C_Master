#ifndef  I2C_H  
#define  I2C_H

#include "stm32f10x.h"   

#define ADXLADDR        0xA6
#define REG_POWER_ADDR  0x2D
#define REG_DATA_FORMAT 0x31
#define REG_DATA_X_LOW  0x32
#define REG_DATA_X_HIGH 0x33
#define REG_DATA_Y_LOW  0x34
#define REG_DATA_Y_HIGH 0x35
#define REG_DATA_Z_LOW  0x36
#define REG_DATA_Z_HIGH 0x37
   
#define PIN_SCL    GPIO_Pin_5  
#define PIN_SDA    GPIO_Pin_4
#define PIN_SCL1   GPIO_Pin_3  
#define PIN_SDA1   GPIO_Pin_2
#define PIN_SCL2   GPIO_Pin_1  
#define PIN_SDA2   GPIO_Pin_0  
#define I2C_PORT   GPIOE  


void Init_ADXL345(void); 
void Init_ADXL3451(void); 
void Init_ADXL3452(void); 

void SDA_IN(void);  
void SDA1_IN(void);  
void SDA2_IN(void);  

void SDA_OUT(void);
void SDA1_OUT(void);
void SDA2_OUT(void);

void I2C_Initi(void);                      
void I2C_Initi1(void);                 
void I2C_Initi2(void);                  

void I2C_Start(void);       
void I2C_Start1(void);  
void I2C_Start2(void);  

void I2C_Stop(void);     
void I2C_Stop1(void);
void I2C_Stop2(void);

void I2C_Send_Byte(u8 txd); 
void I2C_Send_Byte1(u8 txd);
void I2C_Send_Byte2(u8 txd);

u8 I2C_Read_Byte(unsigned char ack);   
u8 I2C_Read_Byte1(unsigned char ack);   
u8 I2C_Read_Byte2(unsigned char ack);   

u8 I2C_Wait_Ack(void); 
u8 I2C_Wait_Ack1(void);
u8 I2C_Wait_Ack2(void);

u8 I2C_Wait_Ack(void);  
u8 I2C_Wait_Ack1(void);
u8 I2C_Wait_Ack2(void);

void I2C_NAck(void);      
void I2C_NAck1(void);   
void I2C_NAck2(void);   

void SingleWrite(u8 daddr,u8 addr,u8 data); 
void SingleWrite1(u8 daddr,u8 addr,u8 data); 
void SingleWrite2(u8 daddr,u8 addr,u8 data); 

u8 SingleRead(u8 daddr,u8 addr);     
u8 SingleRead1(u8 daddr,u8 addr);  
u8 SingleRead2(u8 daddr,u8 addr);  

#endif 
