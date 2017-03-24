#include "Item.h"
#include "sort.h"
#include "stack.h"

#define STACKpush2(A, B)   STACKpush(B); STACKpush(A);

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
	
	STACKinit();
	
	STACKpush2(l, r);
	
	while (STACKcount() > 0) {
		
		l = STACKpop();
		r = STACKpop();
		
		if (r <= l)
			continue;
		
		i = partition(a, l, r);
		
		if (i-l > r-i) {
			STACKpush2(l, i-1);
			STACKpush2(i+1, r);
		} else {
			STACKpush2(i+1, r);
			STACKpush2(l, i-1);
		}
	}
}

