#include <stdlib.h>
#include <stdio.h>
#include "STACK.h"

typedef struct STACKnode *snode;
struct STACKnode {
		int item;
		snode next;
};
static snode head;

static snode NEW(int item, snode next) {
	snode x = malloc(sizeof(*x));
	if (x != NULL) {
		x->item = item;
		x->next = next;
	}
	return x;
}

void STACKinit(void) {
	head = NULL;
}

int STACKcount(void) {
	int i;
	snode x;
	
	for (i = 0, x = head; x != NULL; x = x->next, ++i)
		;
		
	return i;
}

void STACKpush(int item) {
	head = NEW(item, head);
}

int STACKpop(void) {
	int item = head->item;
	snode t = head->next;
	free(head);
	head = t;
	
	return item;
}
