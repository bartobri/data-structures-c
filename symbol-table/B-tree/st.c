#include <stdlib.h>
#include "item.h"
#include "st.h"
#include <stdio.h>

#define M 6

typedef struct STnode *link;
typedef struct {
	Key key;
	union {
		link next;
		Item item;
	} ref;
} entry;
struct STnode {
	entry b[M];
	int m;
};
static link head;
static int H, N;

link NEW(void) {
	link x = malloc(sizeof(*x));
	x->m = 0;
	return x;
}

void STinit(void) {
	head = NEW();
	H = 0;
	N = 0;
}

Item STsearchR(link h, Key v, int height) {
	int j;
	if (height == 0) {
		for (j = 0; j < h->m; ++j) {
			if (eqkey(v, h->b[j].key)) {
				return h->b[j].ref.item;
			}
		}
	}
	if (height != 0) {
		for (j = 0; j < h->m; ++j) {
			if ((j+1 == h->m) || lesskey(v, h->b[j+1].key)) {
				return STsearchR(h->b[j].ref.next, v, height-1);
			}
		}
	}
	return NULLitem;
}

Item STsearch(Key v) {
	return STsearchR(head, v, H);
}

link STsplit(link h) {
	int j;
	link t = NEW();
	for (j = 0; j < M/2; ++j) {
		t->b[j] = h->b[M/2+j];
	}
	h->m = M/2;
	t->m = M/2;
	return t;
}

link STinsertR(link h, Item item, int height) {
	int i, j;
	Key v = key(item);
	entry x;
	link t, u;
	
	x.key = v;
	x.ref.item = item;
	
	if (height == 0) {
		for (j = 0; j < h->m; ++j) {
			if (lesskey(v, h->b[j].key)) {
				break;
			}
		}
	}
	if (height != 0) {
		for (j = 0; j < h->m; ++j) {
			if ((j+1 == h->m) || lesskey(v, h->b[j+1].key)) {
				t = h->b[j++].ref.next;
				u = STinsertR(t, item, height-1);
				if (u == NULL) {
					return NULL;
				}
				x.key = u->b[0].key;
				x.ref.next = u;
				break;
			}
		}
	}
	for (i = (h->m)++; i > j; --i) {
		h->b[i] = h->b[i-1];
	}
	h->b[j] = x;
	if (h->m < M) {
		return NULL;
	} else {
		return STsplit(h);
	}
}

void STinsert(Item item) {
	link t;
	link u = STinsertR(head, item, H);
	if (u == NULL) {
		return;
	}
	t = NEW();
	t->m = 2;
	t->b[0].key = head->b[0].key;
	t->b[0].ref.next = head;
	t->b[1].key = u->b[0].key;
	t->b[1].ref.next = u;
	head = t;
	++H;
}

void STsortR(link h, void (*visit)(Item), int height) {
	int j;

	if (height == H) {
		for (j = 0; j < h->m; ++j) {
			visit(h->b[j].ref.item);
		}
	} else {
		for (j = 0; j < h->m; ++j) {
			STsortR(h->b[j].ref.next, visit, height+1);
		}
	}
}

void STsort(void (*visit)(Item)) {
	STsortR(head, visit, 0);
}

int STcountR(link h, int height) {
	int j, c = 0;
	
	if (height == H) {
		return h->m;
	}
	
	for (j = 0; j < h->m; ++j) {
		c += STcountR(h->b[j].ref.next, height+1);
	}

	return c;
}

Item STselectR(link h, int k, int height) {
	int j, c, t = 0;

	if (height == H) {
		for (j = 0; j < h->m; ++j, --k) {
			if (k == 1) {
				return h->b[j].ref.item;
			}
		}
	} else {
		for (j = 0; j < h->m; ++j) {
			c = STcountR(h->b[j].ref.next, height+1);
			if (t + c >= k) {
				return STselectR(h->b[j].ref.next, k-t, height+1);
			} else {
				t += c;
			}
		}
	}
	
	return NULLitem;
}

Item STselect(int k) {
	return STselectR(head, k, 0);
}

void STdeleteR(link h, Key v, int height) {
	int j;
	if (height == 0) {
		for (j = 0; j < h->m; ++j) {
			if (eqkey(v, h->b[j].key)) {
				h->m -= 1;
				for (; j < h->m; ++j) {
					h->b[j] = h->b[j+1];
				}
				return;
			}
		}
	}
	if (height != 0) {
		for (j = 0; j < h->m; ++j) {
			if ((j+1 == h->m) || lesskey(v, h->b[j+1].key)) {
				return STdeleteR(h->b[j].ref.next, v, height-1);
			}
		}
	}
	return;
}

void STdelete(Key v) {
	STdeleteR(head, v, H);
}



