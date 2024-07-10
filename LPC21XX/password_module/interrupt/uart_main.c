*/
/*

   /*
u8 temp;
uart0_init(9600);
while(1)
{
temp=uart0_rx();
uart0_tx(temp);
}
*/
/*
u8 temp;
u32 i=0x80;
uart0_init(9600);
lcd_init();
lcd_cmd(i);
while(1)
{
temp=uart0_rx();
lcd_data(temp);
i++;
if(i==0x90)
{
i=0xc0;
lcd_cmd(i);
}
if(i==0xd0)
{
lcd_cmd(0x01);
i=0x80;
}
}
*/
/*
uart0_init(9600);
uart0_tx('S');




u8 count=0;
s8 arr[]="Switch is pressed 00 times\r\n";
uart0_init(9600);
while(1)
{
if(SW==0)
{
while(SW==0);
count++;
if(count==100)
count=1;
arr[18]=(count/10)+48;
arr[19]=(count%10)+48;
uart0_tx_string(arr);
}
}
*/
#include<LPC21XX.H>
#include "header.h"
u8 temp;
uart0_init(9600);
while(1)
{
uart0_tx_string("\r\nEnter char : ");
temp=uart0_rx();
uart0_tx(temp);
while(uart0_rx()!='\r');
uart0_tx_string("\r\nASCII : ");
uart0_tx_integer(temp);
uart0_tx(' ');
uart0_tx_hexa(temp);
uart0_tx(' ');
uart0_tx_oct(temp);
}

/*
#include<LPC21XX.H>
#include "header.h"

u8 temp;
s8 pos;
uart0_init(9600);
lcd_init();
while(1)
{
lcd_cmd(0x80);
uart0_tx_string("Enter char : ");
lcd_string("Enter char : ");
temp=uart0_rx();
uart0_tx(temp);
lcd_data(temp);
while(uart0_rx()!='\r');
lcd_cmd(0xc0);
uart0_tx_string("\r\nBinary : ");
lcd_string("Bin : ");
pos=7;
while(pos>=0)
{
if((temp>>pos)&1)
{
uart0_tx('1');
lcd_data('1');
}
else
{
uart0_tx('0');
lcd_data('0');
}
pos--;
}
uart0_tx_string("\r\n");
}
*/*
