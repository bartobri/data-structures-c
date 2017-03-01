#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode *node;
struct STACKnode {
	Item item;
	node next;
};

struct stack {
	node head;
};

node NEW(Item item, node next) {
	node t = malloc(sizeof(*t));
	t->item = item;
	t->next = next;
	return t;
}

S STACKinit(int maxN) {
	S s = malloc(sizeof(*s));
	s->head = NULL;
	return s;
}

int STACKempty(S s) {
	return s->head == NULL;
}

void STACKput(S s, Item item) {
	if (s->head == NULL)
		s->head = NEW(item, NULL);
	else
		s->head = NEW(item, s->head);
}

Item STACKget(S s) {
	Item item = s->head->item;
	node t = s->head;
	s->head = s->head->next;
	free(t);
	return item; 
}
