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

#define CLEARTERM "\e[1;1H\e[2J"

#include "uart.h"

void init_uart(USART_data_t *uart, USART_t *usart, uint32_t f_cpu, uint32_t baud, uint8_t clk2x);

#define UPDATEINTERVAL 1000

int main(void){
	
	SystemClock_init();										// 32 MHz clock
	// Green = RX, Orange = TX
	init_uart(&uartC0, &USARTC0, F_CPU, C0_BAUD, C0_CLK2X); // Module communication		C2 RX C3 TX
	init_uart(&uartC1, &USARTC1, F_CPU, C1_BAUD, C1_CLK2X); // Debug communication		C6 RX C7 TX

	PMIC.CTRL = PMIC_LOLVLEN_bm;
	sei();
	
	char* message;
	
	while(1) {
		_delay_ms(UPDATEINTERVAL);

		DebugPrint("\r\nmessage:\r\n");
//		Command(GFWV);
		DebugPrint(TranslateMessage());
/*		message = TranslateMessage();
		
		if (ValidateMessage(message,TYPE_RRN) == true){
			DebugPrint("My anaconda");
		}
*/
	}
}