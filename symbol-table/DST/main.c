#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 100
#define MAXKEY 100

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
	
	
	printf("Current count: %i\n", STcount());
	
	for (i = 0; i < N; ++i) {
		x = STsearch(i);
		if (x == NULLitem) {
			printf("Could not find key  %i\n", i);
		} else {
			printf("Found key  %i\n", x->key);
		}
	}
	
	return 0;
}
