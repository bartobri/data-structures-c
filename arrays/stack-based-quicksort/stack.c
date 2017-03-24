#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "stack.h"

typedef struct STACKnode *link;
struct STACKnode {
		int item;
		link next;
};
static link head;

link NEW(Item item, link next) {
	link x = malloc(sizeof(*x));
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
	link x;
	
	for (i = 0, x = head; x != NULL; x = x->next, ++i)
		;
		
	return i;
}

void STACKpush(Item item) {
	head = NEW(item, head);
}

Item STACKpop(void) {
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	
	return item;
}
