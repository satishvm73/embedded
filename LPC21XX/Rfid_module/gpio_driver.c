
p1.c
/*p1.c*/
#include<LPC21xx.H>
#include"header.h"
#define LED 0XFF
#define SW ((IOPIN0>>14)&1)
#define SW1 ((IOPIN0>>8)&1)
#define SW2 ((IOPIN0>>9)&1)
#define SW3 ((IOPIN0>>10)&1)
#define SW4 ((IOPIN0>>11)&1)
main()
{
//delay functions
/* delay_sec(1); //1 sec delay
delay_ms(100); //100 ms delay
*/
//GPIO
/*
IODIR0=0XFF;
IOSET0=0X1F;
IOCLR0=0X0F;
*/
//ACTIVE HIGH LED
/*
IODIR0=0XFF;
while(1)
{
IOSET0=0XFF;
delay_ms(200);
IOCLR0=0XFF;
delay_ms(200);
}
*/
//ACTIVE LOW LED
/*
IODIR0=LED;
while(1)
{
IOCLR0=LED;
delay_ms(500);
IOSET0=LED;
delay_ms(500);
}
*/
//blink p0.0 to p0.2
/*
IODIR0=7;
while(1)
{
IOCLR0=7;
delay_ms(500);
IOSET0=7;
delay_ms(500);
}
*/
//blink p0.5 to p0.7
/*
IODIR0=7<<5;
while(1)
{
IOCLR0=7<<5;
delay_ms(200);
IOSET0=7<<5;
delay_ms(200);
}
*/
//blink 8 leds
/*
IODIR0=LED;
while(1)
{
IOCLR0=LED;
delay_ms(500);
IOSET0=LED;

