#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "pq.h"

#define N 20

int main(void) {
	int i;
	PQ a, b;
	
	srand(time(NULL));
	
	a = PQinit();
	b = PQinit();

	for (i = 0; i < N; ++i) {
		PQinsert(a, (rand() % N));
	}
	
	PQcopy(a, b);
	
	while (!PQempty(b)) {
		printf("%i ", PQdelmax(b));
	}
	printf("\n");
	
	PQdestroy(a);
	PQdestroy(b);
	
	return 0;
}
