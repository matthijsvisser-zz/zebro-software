/**
 *	File	transceive.c
 *	Created 17-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Determines the meaning of the message
 * @param  value    received value
 */
// void Determine (){
// 	unsigned char value; 
// 	value = uart_getchar()

// 	switch(value){
// 		case '=':
// 			break;
// 		case:
// 			break;
// 		default:
// 			printf("%c\n", value);	
// 			break;	
// 	}
// }

/**
 * Translates the received message converts characters
 * to a single string
 * @param  	value	received value
 * @return	message pointer to the translated message
 */
char * TranslateMessage (void){
	char value [2];
	static char message[20];

	value[0] = getchar();
	//value[0] = uart_getchar(stdin);
	strcpy(message, value);
	
	while (value[0] != '\n'){
		value[0] = getchar();
		//value[0] = uart_getchar(stdin);	
		strcat(message, value);
	}
	return message;
}

int main (void){
	system("clear");
	printf("%s",TranslateMessage());

	return 0;
}