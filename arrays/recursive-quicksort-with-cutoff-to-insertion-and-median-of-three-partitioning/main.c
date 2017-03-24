#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "sort.h"

#define N 50

int main(void) {
	int i;
	Item a[N];
	
	srand(time(NULL));
	
	// Generate Random Array
	for (i = 0; i < N; ++i) {
		a[i] = rand() % N;
	}
	
	// Print Array
	for (i = 0; i < N; ++i) {
		printf("%i ", a[i]);
	}
	printf("\n");
	
	// Sort Array
	sort(a, 0, N-1);
	
	// Print Array
	for (i = 0; i < N; ++i) {
		printf("%i ", a[i]);
	}
	printf("\n");
	
	return 0;
}
