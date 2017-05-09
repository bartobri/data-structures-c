#include <stdlib.h>
#include "st.h"

#define null(A) (st[A] == NULLitem)

static int N, M;
static Item *st;

void STinit(int max) {
	int i;
	N = 0;
	M = 2*max;
	st = malloc(M * sizeof(Item));
	for (i = 0; i < M; ++i) {
		st[i] = NULLitem;
	}
}

int STcount(void) {
	return N;
}

void STinsert(Item item) {
	Key v = key(item);
	int i = hash(v, M);
	while (!null(i)) {
		i = (i + 1) % M;
	}
	st[i] = item;
	++N;
}

Item STsearch(Key v) {
	int i = hash(v, M);
	while (!null(i)) {
		if (eqkey(v, key(st[i]))) {
			return st[i];
		} else {
			i = (i + 1) % M;
		}
	}
	return NULLitem;
}

void STdelete(Item item) {
	int i = hash(key(item), M);
	int j;
	Item v;
	
	while (!null(i)) {
		if (eq(item, st[i])) {
			break;
		} else {
			i = (i + 1) % M;
		}
	}
	if (null(i)) {
		return;
	}
	
	st[i] = NULLitem;
	--N;
	
	for (j = (i + 1) % M; !null(j); j = (j + 1) % M, --N) {
		v = st[j];
		st[j] = NULLitem;
		STinsert(v);
	}
}

/* 
 * Since the list is not in order, select and sort are not suported.
 * 
Item STselect(int k) {
	return st[k];
}

void STsort(void (*visit)(Item)) {
	int i;
	
	for (i = 0; i < N; ++i) {
		visit(st[i]);
	}
}
*/
