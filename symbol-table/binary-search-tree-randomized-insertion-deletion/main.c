#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N      50
#define MAXKEY 100

int main(void) {
	int i;
	Item x;
	
	srand(time(NULL));

	// Init tree
	STinit();
		
	// Adding N random keys
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % MAXKEY;
		x->data = rand() % 1000;
		STinsert(x);
	}

	// Searching keys
	for (i = 0; i < MAXKEY; ++i) {
		x = STsearch(i);
		if (x != NULLitem) {
			printf("Found key %i\n", key(x));
		}
	}

	// Deleting all data
	for (i = 0; i < MAXKEY; ++i) {
		while (STsearch(i) != NULLitem) {
			STdelete(i);
		}
	}

	
	return 0;
}
