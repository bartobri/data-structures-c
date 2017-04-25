#include <stdlib.h>
#include "st.h"

static Item *st;
static int N;

void STinit(int maxN) {
	st = malloc((maxN) * sizeof(Item));
	N = 0;
}

int STcount(void) {
	return N;
}

void STinsert(Item item) {
	int i = N++;
	
	while (i > 0 && less(item, st[i-1])) {
		st[i] = st[i-1];
		--i;
	}
	
	st[i] = item;
}

Item STsearchR(int l, int r, Key v) {
	int m = (l+r)/2;
	
	if (l > r) {
		return NULLitem;
	}
	
	if (eqkey(v, key(st[m]))) {
		return st[m];
	}
	
	if (l == r) {
		return NULLitem;
	}
	
	if (lesskey(v, key(st[m]))) {
		return STsearchR(l, m-1, v);
	} else {
		return STsearchR(m+1, r, v);
	}
}

Item STsearch(Key v) {
	return STsearchR(0, N-1, v);
}

/*
 * Note that this delete function is not optimized relative to the search
 * function. In theory it should use a similar algorithm to find
 * the item and then remove it from the array.
 */
void STdelete(Item item) {
	int i;
	
	for (i = 0; i < N; ++i) {
		if (eq(item, st[i])) {
			while (i < N) {
				st[i] = st[i+1];
				++i;
			}
			--N;
		}
	}
}

Item STselect(int k) {
	return st[k];
}

void STsort(void (*visit)(Item)) {
	int i;
	
	for (i = 0; i < N; ++i) {
		visit(st[i]);
	}
}
