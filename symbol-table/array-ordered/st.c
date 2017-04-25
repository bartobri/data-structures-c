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

Item STsearch(Key v) {
	int i;
	Item x = malloc(sizeof(*x));
	
	x->key = v;
	
	for (i = 0; i < N; ++i) {
		if (eq(x, st[i])) {
			free(x);
			return st[i];
		}
		if (less(x, st[i])) {
			free(x);
			break;
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

Item STselect(int k) {
	return st[k];
}

void STsort(void (*visit)(Item)) {
	int i;
	
	for (i = 0; i < N; ++i) {
		visit(st[i]);
	}
}
