#include <stdlib.h>
#include "GRAPH.h"

static int **adj;

void graphInit(int S) {
	int i, j;

	// Allocate memory for 2d array
	adj = malloc(S * sizeof(int *));
	for (i = 0; i < S; ++i) {
		adj[i] = malloc(S * sizeof(int));
	}
	
	// Initalize values to zero
	for (i = 0; i < S; ++i)
		for (j = 0; j < S; ++j)
			adj[i][j] = 0;
}

void graphSet(int r, int c) {
	adj[r][c] = 1;
	adj[c][r] = 1;
}

int graphGet(int r, int c) {
	return adj[r][c];
}
