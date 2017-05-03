#include <stdlib.h>
#include "item.h"
#include "st.h"

#define lgNmax 5

typedef struct STnode *link;
struct STnode {
	Item item;
	link *next;
	int sz;
};
static link head, z;
static int N, lgN;

link NEW(Item item, int k) {
	int i;
	link x = malloc(sizeof(*x));
	x->next = malloc(k * sizeof(link));
	x->item = item;
	x->sz = k;
	for (i = 0; i < k; ++i) {
		x->next[i] = z;
	}
	return x;
}

void STinit(void) {
	N = 0;
	lgN = 0;
	z = NEW(NULLitem, 0);
	head = NEW(NULLitem, lgNmax + 1);
}

int STcount(void) {
	return N;
}

Item STsearchR(link t, Key v, int k) {
	if (t == z) {
		return NULLitem;
	}
	if (t->item != NULLitem) {
		if (eqkey(v, key(t->item))) {
			return t->item;
		}
	}
	if (t->next[k] == z || lesskey(v, key(t->next[k]->item))) {
		if (k == 0) {
			return NULLitem;
		}
		return STsearchR(t, v, k-1);
	}
	return STsearchR(t->next[k], v, k);
}

Item STsearch(Key v) {
	return STsearchR(head, v, lgN);
}

int STrandX(void) {
	int i, j, t = rand();
	for (i = 1, j = 2; i < lgNmax; ++i, j += j) {
		if (t > RAND_MAX / j) {
			break;
		}
	}
	if (i > lgN) {
		lgN = i;
	}
	return i;
}

void STinsertR(link t, link x, int k) {
	Key v = key(x->item);
	if (t->next[k] == z || lesskey(v, key(t->next[k]->item))) {
		if (k < x->sz) {
			x->next[k] = t->next[k];
			t->next[k] = x;
		}
		if (k == 0) {
			return;
		}
		STinsertR(t, x, k-1);
		return;
	}
	STinsertR(t->next[k], x, k);
}

void STinsert(Item item) {
	STinsertR(head, NEW(item, STrandX()), lgN);
	++N;
}

Item STselect(int k) {
	link x;
	for (x = head->next[0]; x != z && k > 1; x = x->next[0], --k) {
		;
	}
	if (x == z || k < 1) {
		return NULLitem;
	} else {
		return x->item;
	}
}

void STdeleteR(link t, Key v, int k) {
	link x = t->next[k];
	if (x->item == NULLitem || !lesskey(key(x->item), v)) {
		if (x->item != NULLitem) {
			if (eqkey(v, key(x->item))) {
				t->next[k] = x->next[k];
			}
		}
		if (k == 0) {
			free(x);
			return;
		}
		STdeleteR(t, v, k-1);
		return;
	}
	STdeleteR(t->next[k], v, k);
}

void STdelete(Key v) {
	STdeleteR(head, v, lgN);
	--N;
}

void STsort(void (*visit)(Item)) {
	link x;
	for (x = head->next[0]; x != z; x = x->next[0]) {
		visit(x->item);
	}
}
