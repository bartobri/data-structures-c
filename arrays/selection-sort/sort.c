#include "Item.h"
#include "sort.h"

void selection(Item a[], int l, int r) {
	int i, j, min;
	for (i = l; i < r; ++i) {
		min = i;
		for (j = i+1; j <= r; ++j) {
			if (less(a[j], a[min])) {
				min = j;
			}
		}
		exch(a[i], a[min]);
	}
}

