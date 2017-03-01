#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "STACK.h"

#define M 10

int main(int argc, char *argv[]) {
	int i, j;
	int N = atoi(argv[1]);
	
	srand(time(NULL));
	
	S stacks[M];

	for (i = 0; i < M; ++i) {
		stacks[i] = STACKinit(N);
	}

	for (i = 0; i < N; ++i) {
		STACKput(stacks[rand() % M], i);
	}

	for (i = 0; i < M; ++i) {
		for (j = 0; !STACKempty(stacks[i]); ++j) {
			printf("%3d ", STACKget(stacks[i]));
		}
		printf("\n");
	}
	
	return 0;
}
