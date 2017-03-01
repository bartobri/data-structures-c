#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "QUEUE.h"

#define M 10

int main(int argc, char *argv[]) {
	int i, j;
	int N = atoi(argv[1]);
	
	srand(time(NULL));
	
	Q queues[M];
	
	for (i = 0; i < M; ++i) {
		queues[i] = QUEUEinit(N);
	}

	for (i = 0; i < N; ++i) {
		QUEUEput(queues[rand() % M], i);
	}

	for (i = 0; i < M; ++i) {
		for (j = 0; !QUEUEempty(queues[i]); ++j) {
			printf("%3d ", QUEUEget(queues[i]));
		}
		printf("\n");
	}
	
	return 0;
}
