#include <stdlib.h>
#include "list.h"

//Create a new link and set data, pointer
link new_link(int data) {
	link x = malloc(sizeof *x);
	x->item = data;
	x->next = NULL;

	return x;
}

// Insert b after a
link insert_after(link a, link b) {
	b->next = a->next;
	a->next = b;
	
	return b;
}
