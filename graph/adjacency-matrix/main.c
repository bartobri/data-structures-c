#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

#define V 8

int main(void) {
	int i, j;
	
	graphInit(V);
	
	graphSet(0, 2);
	graphSet(1, 4);
	graphSet(2, 5);
	graphSet(3, 6);
	graphSet(0, 4);
	graphSet(6, 0);
	graphSet(1, 3);
	
	// Showing matrix
	for (i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			printf("%i ", graphGet(i, j));
		}
		printf("\n");
	}
	
	return 0;
}
