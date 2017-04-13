#include <stdio.h>
#include "item.h"
#include "sort.h"

#define M          35
#define MAX_INPUT  1000000
#define bin(A)     l+count[A]

static Item aux[MAX_INPUT];

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

void radixMSD(Item a[], int l, int r, int w) {
	int i, j;
	int count[R+1];
	
	if (w > bytesword)
		return;
	
	if (r-l <= M) {
		insertion(a, l, r);
		return;
	}
	
	for (j = 0; j < R; ++j) {
		count[j] = 0;
	}
	
	for (i = l; i <= r; ++i) {
		count[digit(a[i], w) + 1]++;
	}
	
	for (j = 1; j < R; ++j) {
		count[j] += count[j-1];
	}
	
	for (i = l; i <= r; ++i) {
		aux[count[digit(a[i], w)]++] = a[i];
	}
	
	for (i = l; i <= r; ++i) {
		a[i] = aux[i-l];
	}
	
	radixMSD(a, l, bin(0)-1, w+1);
	
	for (j = 0; j < R-1; ++j) {
		radixMSD(a, bin(j), bin(j+1)-1, w+1);
	}
}

void sort(Item a[], int l, int r) {
	radixMSD(a, l, r, 0);
}
