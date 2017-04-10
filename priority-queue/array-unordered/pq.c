#include <stdlib.h>
#include "Item.h"

static Item *pq;
static int N;

void PQinit(int maxN) {
	pq = malloc(maxN * sizeof(Item));
	N = 0;
}

int PQempty(void) {
	return N == 0;
}

void PQinsert(Item v) {
	pq[N++] = v;
}

Item PQdelmax(void) {
	int i, max = 0;
	for (i = 1; i < N; ++i) {
		if (less(pq[max], pq[i])) {
			max = i;
		}
	}
	exch(pq[max], pq[N-1]);
	
	return pq[--N];
}
