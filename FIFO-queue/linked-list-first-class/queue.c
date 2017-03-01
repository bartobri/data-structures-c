#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode *node;
struct QUEUEnode {
	Item item;
	node next;
};

struct queue {
	node head;
	node tail;
};

node NEW(Item item, node next) {
	node t = malloc(sizeof(*t));
	t->item = item;
	t->next = next;
	return t;
}

Q QUEUEinit(int maxN) {
	Q q = malloc(sizeof(*q));
	q->head = NULL;
	return q;
}

int QUEUEempty(Q q) {
	return q->head == NULL;
}

void QUEUEput(Q q, Item item) {
	if (q->head == NULL) {
		q->head = NEW(item, NULL);
		q->tail = q->head;
	} else {
		q->tail->next = NEW(item, q->tail->next);
		q->tail = q->tail->next;
	}
}

Item QUEUEget(Q q) {
	Item item = q->head->item;
	node t = q->head;
	q->head = q->head->next;
	free(t);
	return item; 
}
