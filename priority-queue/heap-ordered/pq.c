#include <stdlib.h>
#include "Item.h"

static Item *pq;
static int N;

void fixUp(Item a[], int k) {
	while (k > 1 && less(a[k/2], a[k])) {
		exch(a[k], a[k/2]);
		k = k/2;
	}
}

void fixDown(Item a[], int k, int n) {
	int j;
	
	while(2*k <= n) {
		j = 2*k;
		
		if (j < n && less(a[j], a[j+1])) {
			++j;
		}
		
		if (!less(a[k], a[j])) {
			break;
		}
		
		exch(a[k], a[j]);
		
		k = j;
	}
}

void PQinit(int maxN) {
	pq = malloc((maxN + 1) * sizeof(Item));
	N = 0;
}

int PQempty(void) {
	return N == 0;
}

void PQinsert(Item v) {
	pq[++N] = v;
	fixUp(pq, N);
}

Item PQdelmax(void) {
	exch(pq[1], pq[N]);
	fixDown(pq, 1, N-1);
	return pq[N--];
}
