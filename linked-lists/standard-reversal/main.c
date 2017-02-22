#include <stdio.h>
#include "list.h"

#define N 10

link reverse(link);

int main(void) {
	int i;
	link head, x;
	
	// Population
	head = new_link(0);
	x = head;
	for (i = 1; i < N; ++i) {
		x = insert_after(x, new_link(i));
	}
	
	// Reversal
	head = reverse(head);
	
	// Traversal
	for (x = head; x != NULL; x = x->next) {
		printf("%i\n", x->item);
	}
	
	return 0;
}

link reverse(link x) {
	link t;
	link r = NULL;
	
	while (x != NULL) {
		t = x->next;
		x->next = r;
		r = x;
		x = t;
	}
	
	return r;
}
