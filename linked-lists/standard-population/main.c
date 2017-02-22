#include "list.h"

#define N 10

int main(void) {
	int i;
	link head, x;
	
	head = new_link(0);
	x = head;
	
	for (i = 1; i < N; ++i) {
		x = insert_after(x, new_link(i));
	}
	
	return 0;
}
