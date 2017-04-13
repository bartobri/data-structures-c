#include <stdio.h>
#include "item.h"
#include "sort.h"

void binary_quicksort(Item a[], int l, int r, int w) {
	int i = l;
	int j = r;
	
	if (r <= l || w > bitsword)
		return;
	
	while (j != i) {
		while (digit(a[i], w) == 0 && (i < j)) {
			++i;
		}
		while (digit(a[j], w) == 1 && (j > i)) {
			--j;
		}
		exch(a[i], a[j]);
	}
	
	if (digit(a[r], w) == 0) {
		++j;
	}
	
	binary_quicksort(a, l, j-1, w+1);
	binary_quicksort(a, j, r, w+1);
}

void quicksortB(Item a[], int l, int r) {
	binary_quicksort(a, l, r, 0);
}
