#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 20

int main(void) {
	int i;
	Item x;
	ST myst;
	
	srand(time(NULL));

	myst = STinit(N);
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = i;
		x->data = rand() % 1000;
		STinsert(myst, x);
	}
	
	printf("Current count: %i\n", STcount(myst));
	
	for (i = 0; i < N; ++i) {
		x = STsearch(myst, i);
		printf("Deleting key %i with data value %i\n", i, x->data);
		STdelete(myst, x);
	}
	
	printf("Current count: %i\n", STcount(myst));
	
	return 0;
}
