/*
 * PWM.c
 *
 * Created: 17-3-2015 13:29:14
 *  Author: Menno
 */ 

#include "uart.h"

void uart_init(){
	PORTC_DIRSET = PIN7_bm|PIN5_bm; //PC7 as TX pin as output
	PORTC_DIRCLR = PIN6_bm; //PC6 as RX
	PORTC_DIRSET = PIN4_bm; //ss
	PORTC_OUTSET = PIN4_bm; //active low
	
	// Baud rate selection
	// BSEL = (32000000 / (2^0 * 16*9600) -1 = 207.333 -> BSCALE = 0
	// FBAUD = ( (32000000)/(2^0*16(207+1)) = 9615.384 -> 9600
	
	USARTC1_BAUDCTRLA = 0x11; // 207: 0xCF, 115200: 0x11
	USARTC1_BAUDCTRLB = 0; //Just to be sure that BSCALE is 0

	//Disable interrupts
	USARTC1_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTC1_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	USARTC1_CTRLB = USART_TXEN_bm | USART_RXEN_bm; // And enable high speed mode
}

void uart_init_c0(){
	PORTC_DIRSET = PIN3_bm|PIN1_bm; //PC3 as TX pin as output
	PORTC_DIRCLR = PIN2_bm; //PC2 as RX
	PORTC_DIRSET = PIN0_bm; //ss
	PORTC_OUTSET = PIN0_bm; //active low
	
	// Baud rate selection
	// BSEL = (32000000 / (2^0 * 16*9600) -1 = 207.333 -> BSCALE = 0
	// FBAUD = ( (32000000)/(2^0*16(207+1)) = 9615.384 -> 9600
	
	USARTC0_BAUDCTRLA = 0x11; // 207: 0xCF, 115200: 0x11
	USARTC0_BAUDCTRLB = 0; //Just to be sure that BSCALE is 0

	//Disable interrupts
	USARTC0_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTC0_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm; // And enable high speed mode
}

int uart_putchar_c0 (char c, FILE *stream){
	if (c == '\n')
	uart_putchar('\r', stream);
	
	// Wait for the transmit buffer to be empty
	while ( !( USARTC0.STATUS & USART_DREIF_bm) );
	
	// Put our character into the transmit buffer
	USARTC0.DATA = c;
	
	return 0;
}

int uart_putchar (char c, FILE *stream){
	if (c == '\n')
	uart_putchar('\r', stream);
	
	// Wait for the transmit buffer to be empty
	while ( !( USARTC1.STATUS & USART_DREIF_bm) );
	
	// Put our character into the transmit buffer
	USARTC1.DATA = c;
	
	return 0;
}

char uart_getchar_c0(FILE *stream){
	// Wait for the transmit buffer to be empty
	while ( !( USARTC1.STATUS & USART_TXCIF_bm) );
	
	return USARTC1.DATA;
}

char uart_getchar(FILE *stream){
	// Wait for the transmit buffer to be empty
	while ( !( USARTC0.STATUS & USART_TXCIF_bm) );
	
	return USARTC0.DATA;
}

void debug_uart(char *s) {
	// loop through entire string
	while (*s) {
		//uart_putchar_c0(*s);
		s++;
	}
}
