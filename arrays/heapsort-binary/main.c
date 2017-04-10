#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "sort.h"

#define N 20

int main(void) {
	int i;
	Item a[N+1];
	
	srand(time(NULL));
	
	for (i = 1; i <= N; ++i) {
		a[i] = rand() % N;
	}
	
	heapsort(a, 1, N);

	for (i = 1; i <= N; ++i) {
		printf("%i ", a[i]);
	}
	printf("\n");
	
	return 0;
}
