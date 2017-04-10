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
	link x;

	if (head == NULL) {
		head = NEW(v, head);
		return;
	}
	
	if (less(head->item, v)) {
		head = NEW(v, head);
		return;
	}
	
	for (x = head; x->next != NULL; x = x->next) {
		if (less(x->next->item, v)) {
			break;
		}
	}
	
	x->next = NEW(v, x->next);
}

Item PQdelmax(void) {
	Item r = head->item;
	link x = head->next;
	free(head);
	head = x;
	
	return r;
}
