#include <stdlib.h>
#include "Item.h"

typedef struct PQnode *link;
struct PQnode {
		Item item;
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

void PQinit(void) {
	head = NULL;
}

int PQempty(void) {
	return head == NULL;
}

void PQinsert(Item v) {
	head = NEW(v, head);
}

Item PQdelmax(void) {
	Item r;
	link x, max = head;
	
	for (x = head->next; x != NULL; x = x->next) {
		if (less(max->item, x->item)) {
			max = x;
		}
	}
	
	exch(max->item, head->item);
	
	r = head->item;
	x = head->next;
	free(head);
	head = x;
	
	return r;
}
