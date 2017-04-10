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
	int i;

	pq[N++] = v;

	for (i = N-1; i > 0; --i) {
		if (less(pq[i], pq[i-1])) {
			exch(pq[i-1], pq[i]);
		} else {
			break;
		}
	}
}

Item PQdelmax(void) {
	return pq[--N];
}
