#include "main.h"

#ifndef UART_H_
#define UART_H_

void uart_init (void);
void uart_init_c0 (void);
int uart_putchar(char c, FILE *stream);
int uart_putchar_c0 (char c, FILE *stream);
char uart_getchar(FILE *stream);
void debug_uart(char *s);

#endif /* UART_H_ */