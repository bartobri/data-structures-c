#include <stdlib.h>
#include "item.h"
#include "st.h"

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

link STrotR(link h) {
	link x = h->l;
	h->l = x->r;
	x->r = h;

	h->N = h->r->N + h->l->N + 1;
	x->N = x->r->N + x->l->N + 1;
	
	return x;
}

link STrotL(link h) {
	link x = h->r;
	h->r = x->l;
	x->l = h;

	h->N = h->r->N + h->l->N + 1;
	x->N = x->r->N + x->l->N + 1;
	
	return x;
}

link STpartR(link h, int k) {
	int t = h->l->N;
	
	if (t > k) {
		h->l = STpartR(h->l, k);
		h = STrotR(h);
	}
	
	if (t < k) {
		h->r = STpartR(h->r, k-t-1);
		h = STrotL(h);
	}
	
	return h;
}

link STjoinLR(link a, link b) {
	if (b == z) {
		return a;
	}
	
	b = STpartR(b, 0);
	b->l = a;
	
	b->N = b->r->N + b->l->N + 1;
	
	return b;
}

link STbalanceR(link h) {
	if (h->N < 2) {
		return h;
	}
	
	h = STpartR(h, h->N/2);
	
	h->l = STbalanceR(h->l);
	h->r = STbalanceR(h->r);
	
	h->N = h->r->N + h->l->N + 1;
	
	return h;
}

void STinit(void) {
	head = (z = NEW(NULLitem, 0, 0, 0));
}

int STcount(void) {
	return head->N;
}

Item STsearchR(link h, Key v) {
	Key t;
	
	if (h == z) {
		return NULLitem;
	}
	
	t = key(h->item);
	
	if (eqkey(v, t)) {
		return h->item;
	}
	
	if (lesskey(v, t)) {
		return STsearchR(h->l, v);
	} else {
		return STsearchR(h->r, v);
	}
}

Item STsearch(Key v) {
	return STsearchR(head, v);
}

link STinsertR(link h, Item item) {
	Key v, t;
	
	if (h == z) {
		return NEW(item, z, z, 1);
	}
	
	v = key(item);
	t = key(h->item);

	if (lesskey(v, t)) {
		h->l = STinsertR(h->l, item);
	} else {
		h->r = STinsertR(h->r, item);
	}

	(h->N)++;
	
	return h;
}

void STinsert(Item item) {
	head = STinsertR(head, item);
	
	// Balancing when N is a power of 2
	if (head->N > 2 && (head->N & (head->N - 1)) == 0) {
		head = STbalanceR(head);
	}
}

Item STselectR(link h, int k) {
	int t;
	
	if (h == z) {
		return NULLitem;
	}
	
	t = (h->l == z) ? 0 : h->l->N;
	
	if (t > k) {
		return STselectR(h->l, k);
	}
	
	if (t < k) {
		return STselectR(h->r, k-t-1);
	}
	
	return h->item;
}

Item STselect(int k) {
	return STselectR(head, k);
}

link STdeleteR(link h, Key v) {
	int p = 0;
	link x;
	Key t = key(h->item);
	
	if (h == z) {
		return z;
	}
	
	if (lesskey(v, t)) {
		if (h->l != z) {
			p = 1;
		}
		h->l = STdeleteR(h->l, v);
		if (h->l != z || (p == 1 && h->l == z)) {
			--(h->N);
		}
	}
	
	if (lesskey(t, v)) {
		if (h->r != z) {
			p = 1;
		}
		h->r = STdeleteR(h->r, v);
		if (h->r != z || (p == 1 && h->r == z)) {
			--(h->N);
		}
	}
	
	if (eqkey(v, t)) {
		x = h;
		h = STjoinLR(h->l, h->r);
		free(x);
	}
	
	return h;
}

void STdelete(Key v) {
	head = STdeleteR(head, v);
}

void STsortR(link h, void (*visit)(Item)) {
	if (h == z) {
		return;
	}
	
	STsortR(h->l, visit);
	visit(h->item);
	STsortR(h->r, visit);
}

void STsort(void (*visit)(Item)) {
	STsortR(head, visit);
}
