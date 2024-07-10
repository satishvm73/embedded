password.c
#include"header.h"
main()
{
u8 pass[5],head[5],ans[4],p[]="1234",aut[]="5678";
int c=0,f=0,d=0,ra;
uart0_init(9600);
ra=fl;
while(1)
{
if(c==3)
{
ra=!ra;
fl=ra;
c++;
}
if(ra)
{
uart0_tx_string("\r\nEnter password : ");
uart0_rx_string_pas(pass,4);
if(strcmp(pass,p)==0)
{
c=0;
uart0_tx_string("\r\ncorrect password ");
}
else
{
c++;
uart0_tx_string("\r\nwrong password ");
}
}
else
{
f++;
}
if(f==1)
{
uart0_tx_string("\r\nsystem is block");
d=1;
}
if(d==1&&SW1==0)
{ while(SW1==0);
uart0_tx_string("\r\nEnter High Authority Password : ");
uart0_rx_string_pas(head,4);
if(strcmp(head,aut)==0)
{
w:
uart0_tx_string("\r\nunblock system (yes/no): ");
uart0_rx_string_pas(ans,3);
if(strcmp(ans,"yes")==0)
{
ra=!ra;
c=0;
d=0;
f=0;
uart0_tx_string("\r\nunblocked successfully");
fl=ra;
}
else if(strcmp(ans,"no")==0)
{
f=0;
}
else
{
uart0_tx_string("\r\nincorrect command");
goto w;
}
}
else
{
f=0;
uart0_tx_string("\r\nWrong password");
}
}
}
}

