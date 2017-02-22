#include <stdlib.h>
#include "list.h"

link new_link(int i) {
	link x = malloc(sizeof *x);
	x->item = i;
	x->next = NULL;

	return x;
}

// Insert b after a
link insert_after(link a, link b) {
	b->next = a->next;
	a->next = b;
	
	return b;
}
