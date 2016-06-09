/**
 *	File	list.h
 *	Created 03-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATASIZE 5
#define FIRSTDATAITEM 0

typedef struct node {
	char* data [DATASIZE];
	struct node * next;
}node_t;

node_t *head = NULL;

int sizeOfList(node_t *head);