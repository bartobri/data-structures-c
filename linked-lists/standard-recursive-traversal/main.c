#include <stdio.h>
#include "list.h"

#define N 10

void visit(link);

int main(void) {
	int i;
	link head, x;
	
	// Population
	head = new_link(0);
	x = head;
	for (i = 1; i < N; ++i) {
		x = insert_after(x, new_link(i));
	}
	
	// Recursive Traversal
	traverse(head, visit);
	
	return 0;
}

void visit(link x) {
	printf("Visited link %i\n", x->item);
}
