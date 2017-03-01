#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode *link;
struct STACKnode {
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

void STACKinit(int maxN) {
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
	link t, x;
	
	if (head != NULL) {
		if (head->item == item) {
			t = head->next;
			free(head);
			head = t;
		} else {
			for (t = head; t->next != NULL; t = t->next) {
				if (t->next->item == item) {
					x = t->next;
					t->next = t->next->next;
					free(x);
					break;
				}
			}
		}
	}
	
	head = NEW(item, head);
}

Item STACKpop(void) {
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	
	return item;
}
