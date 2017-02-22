#include <stdlib.h>

typedef struct node *link;
struct node {
	int item;
	link next;
};

int main(void) {
	
	link x = malloc(sizeof *x);
	
	return 0;
}
