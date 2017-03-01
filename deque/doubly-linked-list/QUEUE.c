#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode *link;
struct QUEUEnode {
	Item item;
	link next;
	link prev;
};

static link head, tail;

link NEW(Item item, link next, link prev) {
	link x = malloc(sizeof(*x));

	x->item = item;
	x->next = next;
	x->prev = prev;

	return x;
}

void QUEUEinit(int maxN) {
	head = NULL;
	tail == NULL;
}

int QUEUEempty(void) {
	return (head == NULL && tail == NULL);
}

void QUEUEputtail(Item item) {
	if (head == NULL && tail == NULL) {
		tail = (head = NEW(item, NULL, NULL));
		return;
	}
	
	tail->next = NEW(item, NULL, tail);
	tail = tail->next;
}

void QUEUEputhead(Item item) {
	if (head == NULL && tail == NULL) {
		tail = (head = NEW(item, NULL, NULL));
		return;
	}
	
	head->prev = NEW(item, head, NULL);
	head = head->prev;
}

Item QUEUEgethead(void) {
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}

Item QUEUEgettail(void) {
	Item item = tail->item;
	link t = tail->prev;
	free(tail);
	tail = t;
	return item;
}
