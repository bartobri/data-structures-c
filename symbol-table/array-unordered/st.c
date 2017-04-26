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
	st[N++] = item;
}

Item STsearch(Key v) {
	int i;
	
	for (i = 0; i < N; ++i) {
		if (eqkey(v, key(st[i]))) {
			return st[i];
		}
	}
	
	return NULLitem;
}

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
