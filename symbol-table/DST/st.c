#include <stdlib.h>
#include "item.h"
#include "st.h"

#include <stdio.h>

typedef struct STnode *link;
struct STnode {
	Item item;
	link l;
	link r;
	int N;
};
static link head, z;

link NEW(Item item, link l, link r, int N) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->l = l;
	x->r = r;
	x->N = N;
	return x;
}

void STinit(void) {
	head = (z = NEW(NULLitem, 0, 0, 0));
}

int STcount(void) {
	return head->N;
}

Item STsearchR(link h, Key v, int w) {
	Key t;
	
	if (h == z) {
		return NULLitem;
	}
	
	t = key(h->item);
	
	if (eqkey(v, t)) {
		return h->item;
	}
	
	if (digit(v, w) == 0) {
		return STsearchR(h->l, v, w+1);
	} else {
		return STsearchR(h->r, v, w+1);
	}
}

Item STsearch(Key v) {
	return STsearchR(head, v, 0);
}

link STinsertR(link h, Item item, int w) {
	Key v, t;
	
	if (h == z) {
		return NEW(item, z, z, 1);
	}

	v = key(item);
	t = key(h->item);

	if (digit(v, w) == 0) {
		h->l = STinsertR(h->l, item, w+1);
	} else {
		h->r = STinsertR(h->r, item, w+1);
	}

	(h->N)++;
	
	return h;
}

void STinsert(Item item) {
	head = STinsertR(head, item, 0);
}
