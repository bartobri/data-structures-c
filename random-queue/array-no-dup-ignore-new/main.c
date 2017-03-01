#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QUEUE.h"
#include "Item.h"

#define N 10

int main(void) {
	int i, t;
	
	srand(time(NULL));

	QUEUEinit(N);
	
	QUEUEput(1);
	QUEUEput(2);
	QUEUEput(3);
	QUEUEput(2);
	QUEUEput(4);
	
	for (i = 0; i < 4; ++i) {
		t = QUEUEget();
		printf("Getting: %i\n", t);
	}

	return 0;
}
