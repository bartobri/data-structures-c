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
	x = head;
	do {
		printf("%i\n", x->item);
		x = x->next;
	} while (x != head);
	
	return 0;
}

link reverse(link x) {
	link t;
	link y = x;
	link r = NULL;
	
	do {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	} while (y != x);
	
	x->next = r;
	
	return r;
}
