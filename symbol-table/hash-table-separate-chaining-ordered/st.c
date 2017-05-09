#include <stdlib.h>
#include "st.h"

typedef struct STnode *link;
struct STnode {
	Item item;
	link next;
};

static link *heads, z;
static int N, M;

static link NEW(Item item, link next) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

void STinit(int max) {
	int i;
	N = 0;
	M = max/5;
	heads = malloc(M * sizeof(link));
	z = NEW(NULLitem, NULL);
	for (i = 0; i < M; ++i) {
		heads[i] = z;
	}
}

int STcount(void) {
	return N;
}

void STinsert(Item item) {
	int i = hash(key(item), M);
	link x;
	
	if (heads[i] == z || less(item, heads[i]->item)) {
		heads[i] = NEW(item, heads[i]);
		++N;
		return;
	}

	for (x = heads[i]; x->next != z; x = x->next) {
		if (less(item, x->next->item)) {
			break;
		}
	}
	
	x->next = NEW(item, x->next);
	
	++N;
}

Item STsearchR(link t, Key v) {
	if (t == z) {
		return NULLitem;
	}

	if (eqkey(t->item->key, v)) {
		return t->item;
	}
	
	return STsearchR(t->next, v);
}

Item STsearch(Key v) {
	return STsearchR(heads[hash(v, M)], v);
}

link STdeleteR(link h, Item item) {
	link x;
	Key t, v;
	
	if (h == z) {
		return z;
	}
	
	t = key(h->item);
	v = key(item);
	
	if (eqkey(v, t)) {
		x = h;
		h = h->next;
		free(x);
	} else {
		h->next = STdeleteR(h->next, item);
	}
	
	return h;
}

void STdelete(Item item) {
	int i = hash(key(item), M);
	heads[i] = STdeleteR(heads[i], item);
	--N;
}

void STshow(void) {
	int i;
	link h;
	for (i = 0; i < M; ++i) {
		printf("List %i: ", i);
		for (h = heads[i]; h != z;  h = h->next) {
			printf("%i ", key(h->item));
		}
		printf("\n");
	}
}
