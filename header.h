Header.h
#include<LPC21XX.h>
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;
typedef signed short int s16;
extern void delay_ms(u32 ms);
extern void delay_sec(u32 sec);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(unsigned char *ptr);
extern void lcd_integer(int num);
extern void lcd_cgram(void);
extern void lcd_float(float num);
extern void uart0_init(u32 baud);
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern u8 uart0_rx_ha(void);
extern void uart0_tx_string(u8 *ptr);
extern void uart0_tx_integer(int num);
extern void uart0_tx_hexa(int num);
extern void uart0_tx_oct(int num);
extern void uart0_rx_string(u8 *ptr,u8 len);
extern void uart0_tx_float(float num);
extern void uart1_init(u32 baud);
extern void uart1_tx(u8 data);
extern u8 uart1_rx(void);
extern u8 uart1_rx_ha(void);
extern void uart1_tx_string(u8 *ptr);
extern void uart1_tx_integer(int num);
extern void uart1_tx_hexa(int num);
extern void uart1_tx_oct(int num);
extern void uart1_rx_string(u8 *ptr,u8 len);
extern void uart1_tx_float(float num);
#define RS 1<<8
#define RW 1<<9
#define EN 1<<10
#define CLEAR 0X01
#define EN_CUR 0X0E
#define LCD8BITMODE 0X38
#define DIR 0X7FF
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
#define THRE1 ((U1LSR>>5)&1)
#define RDR1 (U1LSR&1)
#define SW1 ((IOPIN0>>14)&1)
#define SW2 ((IOPIN0>>15)&1)
#define SW3 ((IOPIN0>>16)&1)
#define LEDCHECK ((IOPIN0>>19)&1)
#define BULB (1<<17)
#define FAN (1<<18)
#define LED (1<<19)
//#define LED (1<<17) //eint0
#define DONE ((ADDR>>31)&1)
//#define ra (*(volatile unsigned int *)0x40000040)
#define fl (*(unsigned int *)(0xE0038000+500))
//#define fl (*(unsigned int *)0xE0018000)
extern void uart0_rx_string_pas(u8 *ptr,u8 len);
extern void uart0_rx_string_calc(u8 *ptr,u8 len);
extern void adc_init(void);
extern u32 adc_read(u8 ch_num);
extern void lcd_float_adc(float num);
extern void config_vic_for_eint0(void);
extern void config_eint0(void);
extern void config_vic_for_timer1(void);
extern void en_timer1_interrupt(void);
//#define LED1 (1<<17)
//#define LED2 (1<<18)
//#define LED3 (1<<19)
extern void config_vic_for_uart0(void);
extern void en_uart0_interrupt(void);
extern void config_vic_for_eint1(void);
extern void config_eint1(void);
extern void config_vic_for_eint2(void);
extern void config_eint2(void);
#define CS0 (1<<7)

