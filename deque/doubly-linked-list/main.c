#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QUEUE.h"
#include "Item.h"

#define N 5

int main(void) {
	int i, t;
	
	srand(time(NULL));

	QUEUEinit(N);
	
	for (i = 0; i < N; ++i) {
		t = rand() % 100;
		
		if (i % 2) {
			QUEUEputhead(t);
			printf("%i to head\n", t);
		} else {
			QUEUEputtail(t);
			printf("%i to tail\n", t);
		}
	}
	
	printf("Next: %d\n", QUEUEgethead());
	printf("Next: %d\n", QUEUEgethead());
	printf("Next: %d\n", QUEUEgethead());
	printf("Next: %d\n", QUEUEgethead());
	printf("Next: %d\n", QUEUEgethead());

	return 0;
}
