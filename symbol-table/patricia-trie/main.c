#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 20

void visit(Item x) {
	if (x == NULLitem) {
		printf("Visited Null Item ??\n");
	} else {
		printf("Visited key %i\n", key(x));
	}
}

int main(void) {
	int i;
	Item x;
	
	srand(time(NULL));

	STinit();
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = i;
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	STsort(visit);
	
	x = STselect(10);
	if (x == NULLitem) {
		printf("Received null item from select\n");
	} else {
		printf("Received key %i from select\n", key(x));
	}
	
	
	return 0;
}
