#include <stdlib.h>
#include <stdio.h>
#include "QUEUE.h"

typedef struct QUEUEnode *qnode;
struct QUEUEnode {
	int item;
	qnode next;
};

static qnode head, tail;

qnode NEW(int item, qnode next) {
	qnode x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

void QUEUEinit(void) {
	head = NULL;
}

int QUEUEempty(void) {
	return head == NULL;
}

void QUEUEput(int item) {
	if (head == NULL) {
		head = (tail = NEW(item, head));
		return;
	}
	tail->next = NEW(item, tail->next);
	tail = tail->next;
}

int QUEUEget(void) {
	int item = head->item;
	qnode t = head->next;
	free(head);
	head = t;
	return item;
}
