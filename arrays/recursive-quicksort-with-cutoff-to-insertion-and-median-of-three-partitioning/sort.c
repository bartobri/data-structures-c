#include "Item.h"
#include "sort.h"

#define M 25

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
		return;
	}
	
	exch(a[(l+r)/2], a[r-1]);
	compexch(a[l], a[r-1]);
	compexch(a[l], a[r]);
	compexch(a[r-1], a[r]);
	
	i = partition(a, l+1, r-1);
	
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}

void sort(Item a[], int l, int r) {
	quicksort(a, l, r);
	insertion(a, l, r);
}

