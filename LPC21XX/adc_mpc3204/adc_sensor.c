
adc_interrupt handling.c
#include"header.h"
u32 flag;
main()
{
u32 adc_out;
float vout,temperature;
lcd_init();
adc_init();
config_vic_for_timer1();
en_timer1_interrupt();
IODIR0=LED1;
while(1)
{
IOCLR0=LED1;
delay_ms(500);
IOSET0=LED1;
delay_ms(500);
if(flag)
{
adc_out=adc_read(1);
vout=(adc_out*3.3)/1023;
temperature=(vout-0.5)/0.01;
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_string("TEMP : ");
lcd_float_adc(temperature);
lcd_data('C');
adc_out=adc_read(2);
vout=(adc_out*3.3)/1023;
temperature=(vout-0.5)/0.01;
lcd_cmd(0xc0);
lcd_string("POT : ");
lcd_float_adc(temperature);
lcd_data('C');
flag=0;
}
}
}
adc_temp_sensor.c
#include"header.h"
main()
{
u32 adc_out;
float vout,temperature;
uart0_init(9600);
adc_init();
uart0_tx_string("ADC\r\n");
while(1)
{
adc_out=adc_read(1);
vout=(adc_out*3.3)/1023;
temperature=(vout-0.5)/0.01;
uart0_tx_float(temperature);
uart0_tx('c');
uart0_tx_string("\r\n");
}
/*
u32 temp;
float vout;
uart0_init(9600);
adc_init();
uart0_tx_string("ADC\r\n");
while(1)

