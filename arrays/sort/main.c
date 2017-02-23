#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int compare(const void *i, const void *j) {
	return (*(int *)i - *(int *)j);
}

int main(void) {
	int i;
	int a[N];
	
	srand(time(NULL));
	
	for (i = 0; i < N; ++i) {
		a[i] = rand() % 100;
		printf("%2i -> %i\n", i, a[i]);
	}
	
	qsort(a, N, sizeof(int), compare);
	
	for (i = 0; i < N; ++i) {
		printf("%2i -> %i\n", i, a[i]);
	}
	
	return 0;
}
