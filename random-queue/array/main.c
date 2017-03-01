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
		QUEUEput(t);
		printf("Putting: %i\n", t);
	}
	
	for (i = 0; i < N; ++i) {
		t = QUEUEget();
		printf("Getting: %i\n", t);
	}

	return 0;
}
