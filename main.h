#ifndef _MAIN_H
#define _MAIN_H

//global variants
u16 add,add1,add2;//Record the bytes
int reg;
char str[32];
char str1[32];
char str2[32];
double ax1,ay1,az1,ax2,ay2,az2,ax3,ay3,az3;
int16_t ax1l,ay1l,az1l,ax2l,ay2l,az2l,ax3l,ay3l,az3l;
int16_t ax1h,ay1h,az1h,ax2h,ay2h,az2h,ax3h,ay3h,az3h;

void Sys_Init(void);
void ADXL_Measure(void);//Read acceleration data fron the sensor
void ADXL_Calculate(void);//calculate the acceleration and change it into string

#endif
