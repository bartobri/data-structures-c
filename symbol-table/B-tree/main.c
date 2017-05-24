#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N      50

void visit(Item item) {
	printf("Item key: %c\n", key(item));
}

int main(void) {
	int i;
	Item x;
	
	srand(time(NULL));

	STinit();

	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % N * 2;
		x->data = rand() % 1000;
		STinsert(x);
	}

	for (i = 0; i < N * 2; ++i) {
		x = STsearch(i);
		if (x != NULLitem) {
			printf("Found key %i\n", key(x));
		}
	}

	return 0;
}
