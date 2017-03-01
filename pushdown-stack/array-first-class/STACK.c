#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

struct stack {
	Item *item;
	int tail;
	int N;
};

S STACKinit(int maxN) {
	S s = malloc(sizeof(*s));
	s->item = malloc(maxN * sizeof(Item));
	s->tail = 0;
	s->N = maxN;
	
	return s;
}

int STACKempty(S s) {
	return s->tail == 0;
}

void STACKput(S s, Item item) {
	s->item[s->tail] = item;
	++(s->tail);
}

Item STACKget(S s) {
	Item item = s->item[s->tail - 1];
	--(s->tail);
	return item;
}
