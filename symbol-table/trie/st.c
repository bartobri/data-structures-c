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
	if (h == z) {
		return NULLitem;
	}
	
	if (h->l == z && h->r == z) {
		if (eqkey(v, key(h->item))) {
			return h->item;
		} else {
			return NULLitem;
		}
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

link STsplit(link p, link q, int w) {
	link t = NEW(NULLitem, z, z, 2);
	
	switch((digit(key(p->item), w) * 2) + digit(key(q->item), w)) {
		case 0:
			t->l = STsplit(p, q, w+1);
			break;
		case 1:
			t->l = p;
			t->r = q;
			break;
		case 2:
			t->r = p;
			t->l = q;
			break;
		case 3:
			t->r = STsplit(p, q, w+1);
			break;
	}
}

link STinsertR(link h, Item item, int w) {
	if (h == z) {
		return NEW(item, z, z, 1);
	}
	
	if (h->l == z && h->r == z) {
		return STsplit(NEW(item, z, z, 1), h, w);
	}

	if (digit(key(item), w) == 0) {
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

Item STselectR(link h, int k) {
	if (h->N < k) {
		return NULLitem;
	}

	if (k == 1 && h->item != NULLitem) {
		return h->item;
	}

	if (h->l->N >= k) {
		return STselectR(h->l, k);
	} else {
		return STselectR(h->r, k - h->l->N);
	}
}

Item STselect(int k) {
	return STselectR(head, k);
}

link STdeleteR(link h, Key v, int w) {
	link x;
	
	if (h == z) {
		return z;
	}
	
	if (h->l == z && h->r == z) {
		if (eqkey(v, key(h->item))) {
			free(h);
		}
		return z;
	}
	
	if (digit(v, w) == 0) {
		h->l = STdeleteR(h->l, v, w+1);
	} else {
		h->r = STdeleteR(h->r, v, w+1);
	}
	
	if (h->l == z && h->r == z) {
		h = z;
	} else {
		h->N = h->l->N + h->r->N;
	}
	
	return h;
}

void STdelete(Key v) {
	head = STdeleteR(head, v, 0);
}

void STsortR(link h, void (*visit)(Item)) {
	if (h == z) {
		return;
	}
	
	STsortR(h->l, visit);
	if (h->item != NULLitem) {
		visit(h->item);
	}
	STsortR(h->r, visit);
}

void STsort(void (*visit)(Item)) {
	STsortR(head, visit);
}
