#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "pq.h"

#define MAXN 20

int main(void) {
	int i;
	
	srand(time(NULL));
	
	PQinit(MAXN);
	
	for (i = 0; i <= MAXN; ++i) {
		PQinsert(rand() % MAXN);
	}
	
	while (!PQempty()) {
		printf("%d ", PQdelmax());
	}
	printf("\n");
	
	return 0;
}
