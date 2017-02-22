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
	
	// Deletes node after head (returns deleted node)
	x = delete_after(head);

	// Freeing memory
	free_link(x);
	
	return 0;
}
