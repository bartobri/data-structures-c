#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "pq.h"

#define MAXN 10

int main(void) {
	int i;
	
	srand(time(NULL));
	
	PQinit(MAXN);

	for (i = 0; i < MAXN; ++i) {
		PQinsert(rand() % 100);
	}
	
	while (!PQempty()) {
		printf("%d ", PQdelmax());
	}
	printf("\n");
	
	return 0;
}
