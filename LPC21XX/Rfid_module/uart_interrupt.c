
uart0_interrupt.c
#include"header.h"
//extern u32 flag,count2;
extern u8 temp;
extern u32 uart_int;
//extern u32 count;
//extern u8 a[16];
//extern u32 flag,index;
void UART0_Handler(void)__irq
{
int num=U0IIR&0x0E;
if(num==0x4)
{
temp=U0RBR;
//U0THR=temp;
uart_int=1;
/*
a[index]=U0RBR;
if(a[index]!='\r')
U0THR=a[index];
index++;
*/
}
if(num==0x2)
{
}
//flag=1;
//count2++;
VICVectAddr=0;
}
void config_vic_for_uart0(void)
{
//VICIntSelect=0;
VICVectCntl0=6|(1<<5);
VICVectAddr0=(int)UART0_Handler;
VICIntEnable|=(1<<6);
}
void en_uart0_interrupt(void)
{
// U0IER=3;
U0IER=1;
}
