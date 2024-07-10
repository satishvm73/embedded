
adcdriver.c
#include"header.h"
void adc_init(void)
{
PINSEL1|=0x15400000;
ADCR=0x00200400;
}
u32 adc_read(u8 ch_num)
{
u32 result=0;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);
while(DONE==0);
ADCR^=(1<<24);
ADCR^=(1<<ch_num);
result=(ADDR>>6)&0x3ff;
return result;
}
mcp3204driver.c
#include"header.h"
u32 mcp3204_read(u8 ch_num)
{
u32 result=0;
u8 byteH=0,byteL=0;
ch_num<<=6;
IOCLR0=CS0;
spi0(0x06);
byteH=spi0(ch_num);
byteL=spi0(0x00);
IOSET0=CS0;
byteH&=0x0f;
result=(byteH<<8)|byteL;
return result;
}
