#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N     50

int main(void) {
	int i;
	Item x;
	
	srand(time(NULL));

	STinit(N);
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % N;
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	printf("Current count: %i\n", STcount());

	for (i = 0; i < N; ++i) {
		while ((x = STsearch(i)) != NULLitem) {
			printf("Deleting key %2i\n", i);
			STdelete(x);
		}
	}
	
	printf("Current count: %i\n", STcount());
	
	return 0;
}
