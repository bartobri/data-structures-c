#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "pq.h"

#define N 20

int main(void) {
	int i;
	PQ a, b;
	PQlink l;
	
	srand(time(NULL));
	
	a = PQinit();
	b = PQinit();

	for (i = 0; i < N; ++i) {
		PQinsert(a, (rand() % N));
	}
	
	while (!PQempty(a)) {
		printf("%i ", PQdelmax(a));
	}
	printf("\n");
	
	for (i = 0; i < N/2; ++i) {
		l = PQinsert(a, (rand() % N));
	}
	for (i = 0; i < N/2; ++i) {
		PQinsert(a, (rand() % N));
	}

	PQchange(a, l, 10);
	
	while (!PQempty(a)) {
		printf("%i ", PQdelmax(a));
	}
	printf("\n");
	
	for (i = 0; i < N/2; ++i) {
		PQinsert(a, (rand() % N));
	}
	for (i = 0; i < N/2; ++i) {
		PQinsert(b, (rand() % N));
	}

	PQjoin(a, b);
	
	while (!PQempty(a)) {
		printf("%i ", PQdelmax(a));
	}
	printf("\n");
	
	PQdestroy(a);
	
	return 0;
}
