#include <stdlib.h>
#include "st.h"

static Item *st;
static int M = 0;
static int N = 0;

void STinit(int maxN) {
	int i;

	st = malloc((maxN+1) * sizeof(Item));

	for (i = 0; i <= maxN; ++i) {
		st[i] = NULLitem;
	}
	
	M = maxN;
}

int STcount(void) {
	return N;
}

void STinsert(Item item) {
	if (st[key(item)] == NULLitem) {
		++N;
	}
	st[key(item)] = item;
}

Item STsearch(Key v) {
	return st[v];
}

void STdelete(Item item) {
	if (st[key(item)] != NULLitem) {
		--N;
	}
	st[key(item)] = NULLitem;
}

Item STselect(int k) {
	int i;
	
	for (i = 0; i < M; ++i) {
		if (st[i] != NULLitem) {
			if (k-- == 0) {
				return st[i];
			}
		}
	}
}

void STsort(void (*visit)(Item)) {
	int i;
	
	for (i = 0; i < M; ++i) {
		if (st[i] != NULLitem) {
			visit(st[i]);
		}
	}
}
