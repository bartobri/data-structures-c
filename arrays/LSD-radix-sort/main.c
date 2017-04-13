#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "item.h"
#include "sort.h"

#define N 100

int main(void) {
	int i;
	Item a[N];
	
	srand(time(NULL));

	for (i = 0; i < N; ++i) {
		a[i] = rand() % N;
	}

	sort(a, 0, N-1);

	for (i = 0; i < N; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
