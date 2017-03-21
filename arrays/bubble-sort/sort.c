#include "Item.h"
#include "sort.h"

void bubble(Item a[], int l, int r) {
	int i, j;
	
	for (i = l; i < r; ++i) {
		for (j = r; j > i; --j) {
			compexch(a[j-1], a[j]);
		}
	}
}

