#include <stdio.h>
#include "item.h"
#include "sort.h"

#define MAX_INPUT  1000000

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

void radixLSD(Item a[], int l, int r) {
	int i, j, w, count[R+1];
	
	//for (w = bytesword/2-1; w >= 0; --w) {
	for (w = bytesword-1; w >= 0; --w) {
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
	}
}

int sort(Item a[], int l, int r) {
	radixLSD(a, l, r);
	//insertion(a, l, r);
}
