#include <stdio.h>
#include "Item.h"

#define maxN 100

static Item aux[maxN];

void insertion(Item a[], int l, int r) {
	int i, j;
	Item v;
	
	for (i = r; i > l; --i) {
		compexch(a[i-1], a[i]);
	}
	
	for (i = l + 2; i <= r; ++i) {
		j = i;
		v = a[i];
		while (less(v, a[j-1])) {
			a[j] = a[j-1];
			--j;
		}
		a[j] = v;
	}
}

void mergeAB(Item c[], Item a[], int N, Item b[], int M) {
	int i, j, k;
	
	for (i = 0, j = 0, k = 0; k < N + M; ++k) {
		if (i == N) {
			c[k] = b[j++];
			continue;
		}
		if (j == M) {
			c[k] = a[i++];
			continue;
		}
		c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
	}
}

void mergesortABr(Item a[], Item b[], int l, int r) {
	int m = (l+r)/2;
	
	if (r-l <= 10) {
		insertion(a, l, r);
		return;
	}
	
	mergesortABr(b, a, l, m);
	mergesortABr(b, a, m+1, r);
	
	mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

void mergesortAB(Item a[], int l, int r) {
	int i;
	
	for (i = l; i <=r; ++i) {
		aux[i] = a[i];
	}
	
	mergesortABr(a, aux, l, r);
}
