#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 20
#define MAXKEY 100

int main(void) {
	int i;
	Item x;
	
	srand(time(NULL));

	STinit(N);
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % MAXKEY;
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	printf("Current count: %i\n", STcount());

	for (i = 0; i < MAXKEY; ++i) {
		while ((x = STsearch(i)) != NULLitem) {
			printf("Deleting key %i has data value %i\n", i, x->data);
			STdelete(x);
		}
	}
	
	printf("Current count: %i\n", STcount());
	
	return 0;
}
