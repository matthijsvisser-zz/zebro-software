  /**
 *	File	list.c
 *	Created 03-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#include "list.h"

char* returnArray[DATASIZE];

void printHeaderList (void){
	printf("\nPopulationlist\n");
    printf("Nr.\t");
    for (int iteration = 0; iteration < DATASIZE; ++iteration){
    	printf("Data[%d]\t", iteration);
    }
    printf("\n");
}

/**
 * Print data from list
 * @param  *head    List variable
 * @param  item 	Used for iteration
 * @param  *current Status pointer to the current memory location
 * @param  data     Data from memory
 * @param  next    Status pointer to the next memory location
 */
void print_list(node_t *head) {
	int item, listNumber = 0;
    node_t *current = head;

    printHeaderList();
    while(current != NULL) {
    	printf("%d\t", listNumber);
        for(item = 0; item < DATASIZE; item++){
        	
        	printf("%s\t",current -> data[item]);
        }  
        printf("\n");
        current = current -> next;
        ++listNumber;
    }
}


/**
 * Appends a data array to the end of the list.
 * @param  *head    List variable
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next    Status pointer to the next memory location
 */
/*void append (node_t *head, int data[DATASIZE]){
	node_t *current = head;
	while (current -> next != NULL){
		current = current -> next;
	}
	current -> next = (struct node *) malloc(sizeof(node_t));
	for (int item = 0; item < DATASIZE; ++item){
		current -> next -> data[item] = data[item];
	}
	current -> next -> next = NULL;
}*/

/**
 * Inserts a data array to the beginning of the list.
 * @param  *head    List variable
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next    Status pointer to the next memory location
 * @param  item 	Used for iteration
 */
void insert (node_t ** head, char* data[DATASIZE]){
	
/*	for (int i = 0; i < DATASIZE; ++i){
		printf("%s\t", dataInternal[i]);
	}
	printf("\n");
*/
	node_t * new_node;
	new_node = (struct node *) malloc(sizeof(node_t));

	for (int item = 0; item < DATASIZE; ++item){

		//(*new_node).data[item] = data[item]
		new_node -> data[item] = data[item];
	}
	new_node -> next = *head;
	*head = new_node;
	
}

/**
 * Reads the first data array from the list and removes it afterwards.
 * @param  *head    List variable
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next     Status pointer to the next memory location
 * @param  item 	Used for iteration
 * @return returnArray Returns a pointer to the array where the data is stored. 
 */
char* pop (node_t ** head){
//  static int returnArray[DATASIZE];
    //print_list(head);
/*
    node_t * next_node = NULL;



    if (*head == NULL) {
    	printf("null\n");
        return NULL;
    }

    next_node = (*head)-> next;

    for (int item = 0; item < DATASIZE; ++item){
    	returnArray[item] = (*head) -> data[item];
    	printf("%s\n", (*head) -> data[item]);
	}

    free(*head);
    *head = next_node;

    printf("test\n");
    //printf("%s\n",returnArray[1]);
    printf("test\n");
*/
	return *returnArray;
}

/**
 * Pops the data array with the given index number from the list and 
 * removes it afterwards.
 * @param  *head    List variable
 * @param  indexNumber Index number of the wanted data array
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next     Status pointer to the next memory location
 * @param  item 	Used for iteration
 * @return returnArray Returns a pointer to the array where the data is stored. 
 */
/*int* popListByNumber(node_t ** head, int indexNumber){
	static int returnArray[DATASIZE];
	node_t *current = *head, *temp_node = NULL;

	if (indexNumber == 0){
		return pop(head);
	}

	for (int item = 0; item < indexNumber-1; ++item){
		if (current -> next == NULL){
			return NULL;
		}
		current = current -> next;
	}

	temp_node = current -> next;

	for (int item = 0; item < DATASIZE; ++item){
    	returnArray[item] = temp_node -> data[item];
	}

	current -> next = temp_node -> next;
	free(temp_node);

	return returnArray;
}*/



/**
 * returns the data array with the given index number from the list.
 * @param  *head    List variable
 * @param  indexNumber Index number of the wanted data array
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next     Status pointer to the next memory location
 * @param  item 	Used for iteration
 * @return returnArray Returns a pointer to the array where the data is stored. 
 */
/*char* viewListByNumber(node_t ** head, int indexNumber){
	node_t *current = *head, *temp_node = NULL;

	if (indexNumber == 0){
//		return pop(head);
	}

	for (int item = 0; item < indexNumber-1; ++item){
		if (current -> next == NULL){
			return NULL;
		}
		current = current -> next;
	}

	temp_node = current -> next;

	for (int item = 0; item < DATASIZE; ++item){
		//printf("%s\n", temp_node -> data[item]);
    	returnArray[item] = (temp_node -> data[item]);
	}

	current -> next = temp_node -> next;
	free(temp_node);

	return returnArray;
}*/

/**
 * Pops the data array with the given value at the first data array
 * from the list andremoves it afterwards.
 * @param  *head    List variable
 * @param  indexNumber Index number of the wanted data array
 * @param  data     Data to write to memory
 * @param  *current Status pointer to the current memory location
 * @param  next     Status pointer to the next memory location
 * @param  item 	Used for iteration
 * @return returnArray Returns a pointer to the array where the data is stored. 
 */
/*int* popListByValue(node_t ** head, int value, int sizeOfList){
	static int returnArray[DATASIZE];
	node_t *current = *head,*temp_node = NULL;
	
	if (current -> data[FIRSTDATAITEM] == value){
		return pop(head);
	}
	// printf("Item %d, data [%d]\n", 0, current -> data[FIRSTDATAITEM]);

	for (int item = 1; item < sizeOfList; ++item){
		temp_node = current -> next;
		printf("Item %d, data [%d]\n", item, temp_node -> data[FIRSTDATAITEM]);
		if(temp_node -> data[FIRSTDATAITEM] == value){
			for (int itemb = 0; itemb < DATASIZE; ++itemb){
    			returnArray[itemb] = temp_node -> data[itemb];
			}
			current -> next = temp_node -> next;
			free(temp_node);

			return returnArray;
		}
		current = current -> next;
	}
}*/

/**
 * Retrieves the amount of data arrays in the list.
 * @param  *head    List variable
 * @param  *current Status pointer to the current memory location
 * @param  next    Status pointer to the next memory location
 * @param  sizeOfList Amount of data arrays in the list.
 */
int sizeOfList(node_t *head){
	int sizeOfList = 1;
	node_t * current = head;

	while (current -> next != NULL){
		current = current -> next;
		sizeOfList++;
	}
	return sizeOfList;
}

void repeat(){
	char* datb[DATASIZE];
	char var0 [] = "abce";
	char var1 [] = "fghi";
	char var2 [] = "jklm";

	system("clear");

	for (int i = 0; i < DATASIZE; ++i){
		datb[i]= var0;
	}
	insert(&head,datb);

	for (int i = 0; i < DATASIZE; ++i){
		datb[i]= var1;
	}
	insert(&head,datb);

	for (int i = 0; i < DATASIZE; ++i){
		datb[i]= var2;
	}
	insert(&head,datb);

	printf("size of list:%d\n",sizeOfList(head));
	print_list(head);
}

int main(void){
	int count=0;
	char* value;

	while(count < 2){
		repeat();
		count++;
	}

//	printf("%d\n", sizeOfList(head));

	printf("POP't information\n");
	//value = popListByValue(&head, 8, sizeOfList(head));
	value = pop(&head);
//	for (int i = 0; i < DATASIZE; ++i){
//		printf("%s\t",value);
//		*value++;
//	}

	print_list(head);

/*	for (int i = 0; i < DATASIZE; ++i){
		printf("%s\t", datb[i]);
	}
	printf("\n");
*/	
/*	for (int i = 0; i < 10; ++i){
		insert(&head,datb);
	}*/
	//append(head,datb);
	




/*
	char* value = 
//	viewListByNumber(&head,2);

	//printf("%s\t",*value);

	for (int i = 0; i < DATASIZE; ++i){
		printf("%s\t",returnArray[i]);
	}
*/


	return 0;
}