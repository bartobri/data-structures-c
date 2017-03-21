#include "Item.h"
#include "sort.h"

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

