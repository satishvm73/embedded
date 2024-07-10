
home automation.c
#include"header.h"
main()
{
u8 cmd,f=0,g=0,h=0;
IODIR0=(BULB|FAN|LED);
IOSET0=(BULB|FAN|LED);
uart0_init(9600);
while(1)
{
if(SW1==0)
{
L:
while(SW1==0);
f=!f;
if(f)
IOCLR0=LED;
else
IOSET0=LED;
}
if(LEDCHECK)
{
uart0_tx_string("\r\nMENU\r\nA. BULB ON\r\nB. BULB OFF\r\nC. FAN
ON\r\nD. FAN OFF\r\nE. BOTH FAN & BULB ON\r\nF. BOTH FAN & BULB OFF\r\
nCOMMAND....");
PINSEL0|=0x5;
cmd=uart0_rx_ha();
if(cmd==0)
goto L;
uart0_tx(cmd);
switch(cmd)
{
case 'A' : IOCLR0=BULB;break;
case 'B' : IOSET0=BULB;break;
case 'C' : IOCLR0=FAN;break;
case 'D' : IOSET0=FAN;break;
case 'E' : IOCLR0=(FAN|BULB);break;
case 'F' : IOSET0=(FAN|BULB);break;
default : uart0_tx_string("\r\n Wrong Command");
}
}
else
{
PINSEL0|=0x0;
if(SW2==0)
{
while(SW2==0);
g=!g;
if(g)
IOCLR0=BULB;
else
IOSET0=BULB;
}
if(SW3==0)
{
while(SW3==0);
h=!h;
if(h)
IOCLR0=FAN;
else
IOSET0=FAN;
}
}
}
