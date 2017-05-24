#include <stdlib.h>
#include "item.h"
#include "st.h"
#include <stdio.h>

#define M 6

typedef struct STnode *link;
struct STnode {
	Item b[M];
	int m;
	int k;
};
static link *dir;
static int d, D, N;

link NEW(void) {
	link x = malloc(sizeof(*x));
	x->m = 0;
	x->k = 0;
	return x;
}

void STinit(void) {
	d = 0;
	N = 0;
	D = 1;
	dir = malloc(D * (sizeof(*dir)));
	dir[0] = NEW();
}

Item STsearchS(link h, Key v) {
	int j;
	for (j = 0; j < h->m; ++j) {
		if (eqkey(v, key(h->b[j]))) {
			return h->b[j];
		}
	}
	return NULLitem;
}

Item STsearch(Key v) {
	return STsearchS(dir[bits(v, 0, d)], v);
}

void STinsertDIR(link t, int k) {
	int i, m, x = bits(key(t->b[0]), 0, k);
	while (d < k) {
		link *old = dir;
		d += 1;
		D += D;
		printf("D = %i\n", D);
		dir = malloc(D * (sizeof(*dir)));
		for (i = 0; i < D; ++i) {
			dir[i] = old[i/2];
		}
		if (d < k) {
			dir[bits(x, 0, d) ^ 1] = NEW();
		}
	}
	for (m = 1; k < d; ++k) {
		m *= 2;
	}
	for (i = 0; i < m; ++i) {
		dir[x * m + i] = t;
	}
}

link STsplit(link h) {
	int j;
	link t = NEW();
	while (h->m == 0 || h->m == M) {
		h->m = 0;
		t->m = 0;
		for (j = 0; j < M; ++j) {
			if (bits(key(h->b[j]), h->k, 1) == 0) {
				h->b[(h->m)++] = h->b[j];
			} else {
				t->b[(t->m)++] = h->b[j];
			}
		}
		t->k = ++(h->k);
	}
	printf("Inserting Dir... %i\n", t->k);
	STinsertDIR(t, t->k);
}

void STinsertS(link h, Item item) {
	int i, j;
	Key v = key(item);
	for (j = 0; j < h->m; ++j) {
		if (lesskey(v, key(h->b[j]))) {
			break;
		}
	}
	for (i = (h->m)++; i > j; --i) {
		h->b[i] = h->b[i-1];
	}
	h->b[j] = item;
	if (h->m == M) {
		printf("Splitting\n");
		STsplit(h);
	}
}

void STinsert(Item item) {
	printf("Inserting key %i\n", key(item));
	STinsertS(dir[bits(key(item), 0, d)], item);
}

/*
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
*/


/* Draw Tree */

/*
static void printnode(Key v, int h) {
	int i;
	
	for (i = 0; i < h; ++i) {
		printf("    ");
	}
	
	printf("%c\n", v);
}

void showTree(link h, int height) {
	int j;

	if (h == NULL) {
		printnode('*', height);
		return;
	}

	for (j = 0; j < M; ++j) {
		if (h->m > j) {
			if (h->b[j].ref.next == NULL) {
				return;
			}
			printnode(h->b[j].key, height);
			showTree(h->b[j].ref.next, height+1);
		} else {
			if (j == 0) {
				return;
			}
			printnode('*', height);
		}
	}
}

*/
void STdraw(void) {
	int i;
	
	printf("D = %i\n", D);
	//for (i = 0; i < D; ++i) {
	//	printf("dir[%i] = \n", i);
	//}
}





