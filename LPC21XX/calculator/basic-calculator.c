basic calc.c
#include"header.h"
main()
{
/*
u8 exp[4],f;
int result;
uart0_init(9600);
while(1)
{
f=1;
uart0_tx_string("\r\nEnter Expression : ");
uart0_rx_string_calc(exp,3);
if(exp[0]<'0'&&exp[0]>'9')
{
uart0_tx_string("\r\nInvalid expression");
f=0;
}
else if(exp[2]<'0'&&exp[2]>'9')
{
uart0_tx_string("\r\nInvalid expression");
f=0;
}
if(f)
{
uart0_tx_string("\r\nresult: ");
switch(exp[1])
{
case '+': result=(exp[0]-48)+(exp[2]-48);
uart0_tx_integer(result);break;
case '-':result=(exp[0]-48)-(exp[2]-48);
uart0_tx_integer(result);break;
case '*': result=(exp[0]-48)*(exp[2]-48);
uart0_tx_integer(result);break;
case '/':if(exp[2]!='0')
{
result=(exp[0]-48)/(exp[2]-48);
uart0_tx_integer(result);
}
else
uart0_tx_string("floating point error");
break;
case '%': if(exp[2]!='0')
result=(exp[0]-48)%(exp[2]-48);
uart0_tx_integer(result);break;
default:
uart0_tx_string("Invalid operator");
}
}
}
*/
u8 exp[4],f;
int result,i=0;
uart0_init(9600);
while(1)
{
f=1;
uart0_tx_string("\r\nEnter Expression : ");
uart0_rx_string_calc(exp,3);
if(exp[i]<'0'&&exp[i]>'9')
{
uart0_tx_string("\r\nInvalid expression");
f=0;

