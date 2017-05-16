#include <stdlib.h>
#include "item.h"
#include "st.h"
#include <stdio.h>

#define R 27

typedef struct STnode *link;
struct STnode {
	link next[R];
};
static link head;

link NEW(void) {
	int i;
	link x = malloc(sizeof(*x));
	for (i = 0; i < R; ++i) {
		x->next[i] = NULL;
	}
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
	
	return STsearchR(h->next[i], v, w+1);
}

Item STsearch(Key v) {
	return STsearchR(head, v, 0);
}

link STinsertR(link h, Item item, int w) {
	Key v = key(item);
	int i = digit(v, w);
	if (h == NULL) {
		h = NEW();
	}
	if (i == NULLdigit) {
		return h;
	}
	h->next[i] = STinsertR(h->next[i], v, w+1);
	return h;
}

void STinsert(Item item) {
	head = STinsertR(head, item, 0);
}
