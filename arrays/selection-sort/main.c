#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "sort.h"

#define N 100

int main(void) {
	int i;
	Item a[N];
	struct timespec t1, t2;
	long diff;
	
	srand(time(NULL));
	
	// Generate Random Array
	for (i = 0; i < N; ++i) {
		a[i].key = rand() % N;
		a[i].val = i;
	}
	
	// Print Array
	for (i = 0; i < N; ++i) {
		printf(" %i ", a[i].key);
	}
	printf("\n");
	
	// Sort Array
	selection(a, 0, N-1);
	
	// Print Array
	for (i = 0; i < N; ++i) {
		printf(" %i ", a[i].key);
	}
	printf("\n");
	
	return 0;
}
