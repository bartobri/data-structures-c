#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

// leaving code for linked-list implementation commented out in case I
// need it later.

//typedef struct QUEUEnode *link;
//struct QUEUEnode {
//	Item item;
//	link next;
//};

struct queue {
	Item *item;
	int head;
	int tail;
	int N;
	//link head;
	//link tail;
};

//link NEW(Item item, link next) {
//	link x = malloc(sizeof(*x));
//	x->item = item;
//	x->next = next;
//	return x;
//}

Q QUEUEinit(int maxN) {
	Q q = malloc(sizeof(*q));
	q->item = malloc(maxN * sizeof(Item));
	q->head = 0;
	q->tail = 0;
	q->N = maxN;
	
	//Q q = malloc(sizeof(*q));
	//q->head = NULL;
	
	return q;
}

int QUEUEempty(Q q) {
	//return q->head == NULL;
	return q->head == q->tail;
}

void QUEUEput(Q q, Item item) {
	q->item[q->tail] = item;
	q->tail = (q->tail + 1) % q->N;
	//if (q->head == NULL) {
	//	q->tail = NEW(item, q->head);
	//	q->head = q->tail;
	//	return;
	//}
	//q->tail->next = NEW(item, q->tail->next);
	//q->tail = q->tail->next;
}

Item QUEUEget(Q q) {
	Item item = q->item[q->head];
	q->head = (q->head + 1) % q->N;
	//Item item = q->head->item;
	//link t = q->head->next;
	//free(q->head);
	//q->head = t;
	return item;
}
