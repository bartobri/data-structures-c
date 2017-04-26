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

	STinit();
	
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = rand() % MAXKEY;
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	
	printf("Current count: %i\n", STcount());
	
	x = STselect(10);
	
	printf("10th smallest key is %i\n", x->key);
	
	printf("Deleting key %i\n", x->key);
	
	STdelete(x->key);
	
	x = STsearch(x->key);
	
	if (x == NULLitem) {
		printf("Key no longer exists\n");
	} else {
		printf("Duplicate key still exists\n");
	}
	
	
	printf("Current count: %i\n", STcount());
	
	return 0;
}
