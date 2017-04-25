#include <stdlib.h>
#include "st.h"

//static Item *st;
//static int M = 100;
//static int N = 0;

struct symbol_table {
	Item *items;
	int count;
	int N;
};

ST STinit(int N) {
	int i;

	ST st = malloc(sizeof(*st));

	st->count = 0;
	st->N = N;
	st->items = malloc(N * sizeof(Item));
	for (i = 0; i <= N; ++i) {
		st->items[i] = NULLitem;
	}
	
	return st;
}

int STcount(ST st) {
	return st->count;
}

void STinsert(ST st, Item item) {
	if (st->items[key(item)] == NULLitem) {
		++(st->count);
	}
	st->items[key(item)] = item;
}

Item STsearch(ST st, Key v) {
	return st->items[v];
}

void STdelete(ST st, Item item) {
	if (st->items[key(item)] != NULLitem) {
		--(st->count);
	}
	st->items[key(item)] = NULLitem;
}

Item STselect(ST st, int k) {
	int i;
	
	for (i = 0; i < st->N; ++i) {
		if (st->items[i] != NULLitem) {
			if (k-- == 0) {
				return st->items[i];
			}
		}
	}
}

void STsort(ST st, void (*visit)(Item)) {
	int i;
	
	for (i = 0; i < st->N; ++i) {
		if (st->items[i] != NULLitem) {
			visit(st->items[i]);
		}
	}
}
