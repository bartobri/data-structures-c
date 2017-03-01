#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "QUEUE.h"

#define N 10

int main(void) {
	QUEUEinit(N);
	
	QUEUEput(1);
	QUEUEput(2);
	QUEUEput(3);
	QUEUEput(2);
	QUEUEput(4);
	printf("Got %i\n", QUEUEget());
	printf("Got %i\n", QUEUEget());
	printf("Got %i\n", QUEUEget());
	printf("Got %i\n", QUEUEget());
	
	return 0;
}
