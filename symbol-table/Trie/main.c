#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 10

void visit(Item x) {
	printf("Visited key %d\n", key(x));
}

int main(void) {
	int i;
	Key keys[N] = {128, 200, 100, 50, 250, 33, 99, 6, 187, 220};
	Item x;
	
	srand(time(NULL));

	STinit();
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = keys[i];
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	STsort(visit);
	
	x = STselect(4);
	if (x != NULLitem) {
		printf("4th key is %d\n", key(x));
	} else {
		printf("4th key is NULLitem\n");
	}
	
	printf("Deleting keys\n");
	for (i = 0; i < N; ++i) {
		STdelete(keys[i]);
		printf("Deleted key %i\n", keys[i]);
	}
	
	return 0;
}
