#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define NMAX      50
#define NINIT     10

int main(void) {
	int i;
	char *keys = "EASYQUTION";
	Item x;
	
	srand(time(NULL));

	STinit(NINIT);

	for (i = 0; i < NMAX; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % NMAX;
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	printf("Current count: %i\n", STcount());

	for (i = 0; i < NMAX; ++i) {
		while ((x = STsearch(i)) != NULLitem) {
			printf("Deleting key %i has data value %i\n", i, x->data);
			STdelete(x);
		}
	}
	
	printf("Current count: %i\n", STcount());
	
	return 0;
}
