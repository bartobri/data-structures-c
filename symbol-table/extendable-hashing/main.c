#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N      9

int main(void) {
	int i;
	Key keys[9] = {562, 221, 240, 771, 274, 233, 401, 273, 201};
	Item x;

	// Init tree
	STinit();
	
	//for (i = 0; i < N; ++i) {
	//	printf("%i -> %i\n", keys[i], bits(keys[i], 0, 0));
	//}
	//return 0;
		
	// Adding N random keys
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = keys[i];
		x->data = rand() % 1000;
		STinsert(x);
	}
	
	STdraw();

	// Searching keys
	/*
	for (i = 0; i < N; ++i) {
		x = STsearch(keys[i]);
		if (x != NULLitem) {
			printf("Found key %c\n", key(x));
		}
	}
	*/

	return 0;
}
