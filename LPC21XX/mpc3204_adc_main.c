main_mcp3204.c
#include"header.h"
main()
{
u32 temp;
uart0_init(9600);
spi0_init();
uart0_tx_string("MCP3204 Test \r\n");
while(1)
{
temp=mcp3204_read(1);
uart0_tx_integer(temp);
uart0_tx_string("\r\n");
delay_ms(500);
}
}

