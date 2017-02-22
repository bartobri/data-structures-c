#include <stdio.h>
#include "list.h"

#define N 10

int main(void) {
	int i;
	link head, x;
	
	// Population
	head = new_link(0);
	x = head;
	for (i = 1; i < N; ++i) {
		x = insert_after(x, new_link(i));
	}
	
	// Traversal
	for (x = head; x != NULL; x = x->next) {
		printf("%i\n", x->item);
	}
	
	return 0;
}
