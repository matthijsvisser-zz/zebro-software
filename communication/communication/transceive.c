/**
 *	File	transceive.c
 *	Created 17-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#include "main.h"
#include "uart.h"
#include "transceive.h"

extern USART_data_t uartC0;
extern USART_data_t uartC1;

/**
 * Validates the integrity of the received message
 * @param   *message   Received message
 * @param   command    Type of command
 * @return  true/false 
 */
uint8_t ValidateMessage (char *message, uint8_t command){
    uint8_t messageLength;
    messageLength = strlen(message) - 2;

    switch (command) {
        case 1: // command RRN
            if (messageLength == RRN_LENGTH){
                return true;
            }
        case 2: // command XX
            if (messageLength == RRN_LENGTH){
                return false;
            }
        case 3: // command XX
            if (messageLength == RRN_LENGTH){
                return false;
            }
        default:
            return false;
    }
}


/**
 * Ranging result notification flag
 * @param  	
 * @param	
 */
void RRN_function (char *message){
	uart_puts(&uartC1, "functieeee\r\n");
}


/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */
void DetermineCommandtype (char *message){
	char *messagePointer;
	char command[5];
	uint8_t count = 0;
	
	memset(command, EOS, strlen(command));	
	messagePointer = message;
	
	DebugPrint("Determing message\r\n");
	DebugPrint(message);
	DebugPrint("\r\n");
	
	while(*messagePointer != ':'){
		if(*messagePointer == ':'){ break;};
		//uart_putc(&uartC1, *messagePointer);
		command[count] = *messagePointer;
		*messagePointer++;
		count++;
	}
	DebugPrint("Command:\r\n");
	DebugPrint(command);
	char test[] = {'*','R','R','N', '\0'};

	if		(strcmp(command,	"*RRN") == 0){	// Data Notification Message
		RRN_function(message);
	}else if(strcmp(command, "DNO") == 0){	// Node ID Notification Message
		
	}else if(strcmp(command, "NIN") == 0){	// Ranging Result Notification Message
		//printf("NIN\n");
	}else if(strcmp(command, "SDAT") == 0){	// SDAT Notification Messages
		//printf("SDAT\n");
	}else if(strcmp(command, "AIR") == 0){	// AIR Notification Message
		//printf("AIR\n");
	}else{
		DebugPrint("No command\r\n");
	}

}

char message[128];

/**
 * Translates the received message converts characters
 * to a single string
 * @param  	value	received value
 * @return	message pointer to the translated message
 */
char * TranslateMessage (void){
	char value[128];

	memset(message, EOS, strlen(message));
	memset(value, EOS, strlen(value));

	value[0] = uart_getc(&uartC0);
	strcpy(message, value);
	while (value[0] != CR){
		if (value[0] != CR){	
			
			strcat(message, value);	
		}
		value[0] = uart_getc(&uartC0);
	}
	return message;
}