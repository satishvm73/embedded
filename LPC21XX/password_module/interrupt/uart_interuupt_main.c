uart0_interrupt.c
#include"header.h"
//u32 count;
//u32 flag;
u8 temp;
u32 flag,count1,count2;
main()
{
uart0_init(9600);
config_vic_for_uart0();
en_uart0_interrupt();
while(1)
{
count1++;
/* if(flag==1)
{
flag=0;
}
*/
}
}
