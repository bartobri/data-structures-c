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
	x = head;
	do {
		printf("%i\n", x->item);
		x = x->next;
	} while (x != head);
	
	return 0;
}
