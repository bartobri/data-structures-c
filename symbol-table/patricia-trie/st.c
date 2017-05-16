#include <stdlib.h>
#include "item.h"
#include "st.h"

#include <stdio.h>

typedef struct STnode *link;
struct STnode {
	Item item;
	link l;
	link r;
	int bit;
};
static link head;
static int N;

link NEW(Item item, link l, link r, int b) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->l = l;
	x->r = r;
	x->bit = b;
	return x;
}

void STinit(void) {
	head = NEW(NULLitem, 0, 0, -1);
	head->l = head;
	head->r = head;
	N = 0;
}

int STcount(void) {
	return N;
}

Item STsearchR(link h, Key v, int w) {
	if (h->bit <= w) {
		return h->item;
	}
	if (digit(v, h->bit) == 0) {
		return STsearchR(h->l, v, h->bit);
	} else {
		return STsearchR(h->r, v, h->bit);
	}
}

Item STsearch(Key v) {
	Item t = STsearchR(head->l, v, -1);
	if (t == NULLitem || eqkey(v, key(t))) {
		return t;
	} else {
		return NULLitem;
	}
}

link STinsertR(link h, Item item, int w, link p) {
	link x;
	Key v = key(item);
	if ((h->bit >= w) || (h->bit <= p->bit)) {
		x = NEW(item, 0, 0, w);
		x->l = digit(v, x->bit) ? h : x;
		x->r = digit(v, x->bit) ? x : h;
		return x;
	}
	
	if (digit(v, h->bit) == 0) {
		h->l = STinsertR(h->l, item, w, h);
	} else {
		h->r = STinsertR(h->r, item, w, h);
	}

	++N;
	
	return h;
}

void STinsert(Item item) {
	int i;
	Key v = key(item);
	Item x = STsearchR(head->l, v, -1);
	Key t = (x == NULLitem) ? 0 : key(x);
	if (v == t) {
		return;
	}
	for (i = 0; digit(v, i) == digit(t, i); ++i)
		;
	head->l = STinsertR(head->l, item, i, head);
}

void STsortR(link h, void (*visit)(Item), int w) {
	if (h->bit <= w) {
		if (h != head) {
			visit(h->item);
		}
		return;
	}
	STsortR(h->l, visit, h->bit);
	STsortR(h->r, visit, h->bit);
}

void STsort(void (*visit)(Item)) {
	STsortR(head->l, visit, -1);
}

Item STselectR(link h, int w, int k) {
	Item x;
	static int c = 0;
	if (h->bit <= w) {
		if (h != head) {
			++c;
		}
		if (k == c) {
			return h->item;
		} else {
			return NULLitem;
		}
	}
	x = STselectR(h->l, h->bit, k);
	if (x != NULLitem) {
		return x;
	}
	x = STselectR(h->r, h->bit, k);
	
	return x;
}

Item STselect(int k) {
	return STselectR(head->l, -1, k);
}
