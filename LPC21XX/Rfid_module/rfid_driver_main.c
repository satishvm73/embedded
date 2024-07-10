rfidproject.c
#include"header.h"
main()
{
/*
u8 rfid[13];
uart0_init(9600);
lcd_init();
while(1)
{
uart0_rx_string(rfid,12);
uart0_tx('\r');
uart0_tx_string(rfid);
lcd_cmd(0x01);
lcd_string(rfid);
}
*/
u8 rfid[13];
uart0_init(9600);
uart1_init(9600);
PINSEL0|=0X10001;
while(1)
{
uart1_rx_string(rfid,12);
uart0_tx_string("\r\n");
uart0_tx_string(rfid);
}
}
string switch interrupt.c
#include"header.h"
#define LED (1<<17)
u32 flag;
main()
{
u8 str[]="shaik shajeed";
u32 i=0;
config_vic_for_eint0();
config_eint0();
IODIR0=LED;
IOSET0=LED;
uart0_init(9600);
while(1)
{
IOCLR0=LED;
delay_ms(100);
IOSET0=LED;
delay_ms(100);
if(flag)
{
if(str[i])
{
uart0_tx(str[i]);
i++;
}
else
VICIntEnable^=(1<<14);
flag=0;
}
}
}
