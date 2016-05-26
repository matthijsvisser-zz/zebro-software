#include "main.h"
static FILE mystdout = FDEV_SETUP_STREAM (uart_putchar, NULL, _FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM (NULL, uart_getchar, _FDEV_SETUP_READ);


int main(void)
{
	//int frequent;
	SystemClock_init();
	uart_init();
	//uart_init_c0();
	stdout = &mystdout;
	stdin  = &mystdin;
	char input;
	//int input;
	//char test[64];
	
	TCC0.CTRLA = TC_CLKSEL_DIV64_gc; // prescaling 8
	TCC0.PER = 0XFFFF; // maximal value
	
	//printf("\e[3J");
	printf("sbiv 1000\n");
	printf("GRWL\n");


	while (1) {
		
		//input = uart_getchar(stdin);
		//printf("%c",input);
		//strcpy(test,TranslateMessage());
		//printf("mennioty - %s\n",test);
		//TranslateMessage(input);
		//TranslateMessage();
		//debug_uart("test");
	}
}