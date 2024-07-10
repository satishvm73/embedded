home automation interrupt.c
#include"header.h"
u32 uart_int,i=1;
u8 temp;
//u32 flag1;
main()
{
IODIR0=(BULB|FAN|LED);
IOSET0=(BULB|FAN|LED);
uart0_init(9600);
config_vic_for_uart0();
en_uart0_interrupt();
config_vic_for_eint0();
config_eint0();
config_vic_for_eint1();
config_eint1();
config_vic_for_eint2();
config_eint2();
while(1)
{
if(i==1)
{
uart0_tx_string("\r\nMENU\r\nA. BULB ON\r\nB. BULB OFF\r\nC.
FAN ON\r\nD. FAN OFF\r\nE. BOTH FAN & BULB ON\r\nF. BOTH FAN & BULB OFF\r\
nCOMMAND....");
i=0;
}
if(uart_int)
{
uart0_tx(temp);
switch(temp)
{
case 'A' : IOCLR0=BULB;break;
case 'B' : IOSET0=BULB;break;
case 'C' : IOCLR0=FAN;break;
case 'D' : IOSET0=FAN;break;
case 'E' : IOCLR0=(FAN|BULB);break;
case 'F' : IOSET0=(FAN|BULB);break;
default : uart0_tx_string("\r\n Wrong Command");
}
uart0_tx_string("\r\nMENU\r\nA. BULB ON\r\nB. BULB OFF\r\nC.
FAN ON\r\nD. FAN OFF\r\nE. BOTH FAN & BULB ON\r\nF. BOTH FAN & BULB OFF\r\
nCOMMAND....");
uart_int=0;
}
}
}
