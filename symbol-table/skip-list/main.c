#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define N      10

void visit(Item item) {
	printf("%c\n", item->key);
}

int main(void) {
	int i;
	Key keys[N] = { 'E', 'A', 'S', 'Y', 'Q', 'U', 'T', 'I', 'O', 'N' };
	Item x;
	
	srand(time(NULL));

	STinit();
	for (i = 0; i < N; ++i) {
		x = malloc(sizeof(*x));
		x->key = keys[i];
		x->data = rand() % 100;
		STinsert(x);
	}
	
	STsort(visit);
	
	x = STsearch('Y');
	printf("data for Y: %i\n", x->data);
	
	STdelete('T');
	printf("Deleted T\n");
	
	STsort(visit);
	
	x = STselect(2);
	printf("key for 2nd item: %c\n", x->key);

	return 0;
}
