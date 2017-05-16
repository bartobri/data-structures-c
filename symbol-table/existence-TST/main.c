#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N 16

int main(void) {
	int i;
	Key keys[N] = {"now", "is", "the", "time", "for", "all", "good", "people", "to", "come", "to", "the", "aid", "of", "their", "party"};
	Item x;
	
	srand(time(NULL));

	STinit();
	
	for (i = 0; i < N; ++i) {
		x = keys[i];
		printf("inserting %s\n", keys[i]);
		STinsert(x);
	}
	
	for (i = 0; i < N; ++i) {
		printf("Searching for key %s... ", keys[i]);
		x = STsearch(keys[i]);
		if (x = NULLitem) {
			printf("Did not find it\n");
		} else {
			printf("Found!\n");
		}
	}
	
	return 0;
}
