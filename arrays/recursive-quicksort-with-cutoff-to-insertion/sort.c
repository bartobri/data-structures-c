#include "Item.h"
#include "sort.h"

#define M 5

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

int partition(Item a[], int l, int r) {
	int i = l - 1;
	int j = r;
	Item v = a[r];
	
	for (;;) {
		while (less(a[++i], v))
			;
		
		while (less(v, a[--j])) {
			if (j == l) {
				break;
			}
		}
		
		if (i >= j) {
			break;
		}
		
		exch(a[i], a[j]);
	}
	
	exch(a[i], a[r]);
	
	return i;
}

void quicksort(Item a[], int l, int r) {
	int i;
	
	if (r - l <= M) {
		insertion(a, l, r);
		return;
	}
	
	i = partition(a, l, r);
	
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}

