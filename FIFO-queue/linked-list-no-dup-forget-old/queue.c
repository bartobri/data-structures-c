#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode *link;
struct QUEUEnode {
	Item item;
	link next;
};

static link head, tail;

link NEW(Item item, link next) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

void QUEUEinit(int maxN) {
	head = NULL;
}

int QUEUEempty(void) {
	return head == NULL;
}

void QUEUEput(Item item) {
	link x, t = head;
	
	if (t != NULL) {
		if (t->item == item) {
			head = t->next;
			free(t);
		} else {
			while (t->next != NULL) {
				if (t->next->item == item) {
					x = t->next;
					t->next = t->next->next;
					free(x);
					break;
				}
				t = t->next;
			}
		}
	}
	
	if (head == NULL) {
		head = (tail = NEW(item, head));
		return;
	}
	tail->next = NEW(item, tail->next);
	tail = tail->next;
}

Item QUEUEget(void) {
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
