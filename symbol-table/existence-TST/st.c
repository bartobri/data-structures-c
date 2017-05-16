#include <stdlib.h>
#include "item.h"
#include "st.h"
#include <stdio.h>

#define R 27

typedef struct STnode *link;
struct STnode {
	int d;
	link l, m, r;
};
static link head;

link NEW(int d) {
	link x = malloc(sizeof(*x));
	x->d = d;
	x->l = NULL;
	x->m = NULL;
	x->r = NULL;
	return x;
}

void STinit(void) {
	head = NULL;
}

Item STsearchR(link h, Key v, int w) {
	int i = digit(v, w);
	
	if (h == NULL) {
		return NULLitem;
	}
	
	if (i == NULLdigit) {
		return v;
	}
	
	if (i < h->d) {
		return STsearchR(h->l, v, w);
	}
	if (i == h->d) {
		return STsearchR(h->m, v, w+1);
	}
	if (i > h->d) {
		return STsearchR(h->r, v, w);
	}
}

Item STsearch(Key v) {
	return STsearchR(head, v, 0);
}

link STinsertR(link h, Item item, int w) {
	Key v = key(item);
	int i = digit(v, w);
	
	if (h == NULL) {
		h = NEW(i);
	}

	if (i == NULLdigit) {
		return h;
	}

	if (i < h->d) {
		h->l = STinsertR(h->l, v, w);
	}
	if (i == h->d) {
		h->m = STinsertR(h->m, v, w+1);
	}
	if (i > h->d) {
		h->r = STinsertR(h->r, v, w);
	}
	
	return h;
}

void STinsert(Item item) {
	head = STinsertR(head, item, 0);
}
