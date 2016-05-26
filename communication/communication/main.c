#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>
//static FILE mystdout = FDEV_SETUP_STREAM (uart_putchar, NULL, _FDEV_SETUP_WRITE);
//static FILE mystdin = FDEV_SETUP_STREAM (NULL, uart_getchar, _FDEV_SETUP_READ);

#define ENABLE_UART_C1   1
#define C1_BAUD          115200    //!< baud rate
#define C1_CLK2X         0         //!< no double clock speed

#define ENABLE_UART_C0   1
#define C0_BAUD          115200    //!< baud rate
#define C0_CLK2X         0         //!< no double clock speed

#include "uart.h"

void init_uart(USART_data_t *uart, USART_t *usart, uint32_t f_cpu, uint32_t baud, uint8_t clk2x);




int main(void)
{
	SystemClock_init();
	init_uart(&uartC0, &USARTC0, F_CPU, C0_BAUD, C0_CLK2X);
	init_uart(&uartC1, &USARTC1, F_CPU, C1_BAUD, C1_CLK2X);

	PMIC.CTRL = PMIC_LOLVLEN_bm;
	sei();
	
	while(1) {
		uart_puts(&uartC0, "hoi menno\r\n");
		_delay_ms(1000);
		uart_puts(&uartC1, "hoi jur\r\n");
		_delay_ms(1000);

	}
	
	
	//int frequent;

	//uart_init();
	//uart_init_c0();
	//stdout = &mystdout;
	//stdin  = &mystdin;
	//char input;
	//int input;
	//char test[64];
	
	//TCC0.CTRLA = TC_CLKSEL_DIV64_gc; // prescaling 8
	//TCC0.PER = 0XFFFF; // maximal value
	
	//printf("\e[3J");
	//printf("sbiv 1000\n");
	//printf("GRWL\n");


	//while (1) {
		
		//input = uart_getchar(stdin);
		//printf("%c",input);
		//strcpy(test,TranslateMessage());
		//printf("mennioty - %s\n",test);
		//TranslateMessage(input);
		//TranslateMessage();
		//debug_uart("test");
	//}
}