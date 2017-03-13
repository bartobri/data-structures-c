#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

#define V 8

void visit(int);

int main(void) {
	int i;
	
	graphInit(V);
	
	graphSet(0, 2);
	graphSet(1, 4);
	graphSet(2, 5);
	graphSet(3, 6);
	graphSet(0, 4);
	graphSet(6, 0);
	graphSet(1, 3);
	
	traverse(0, visit);
	
	return 0;
}

void visit(int x) {
	printf("Visiting item %i\n", x);
}
