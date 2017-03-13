#include <stdlib.h>
#include <stdio.h>
#include "GRAPH.h"

typedef struct node *link;
struct node {
	int v;
	link next;
};
static link *adj;

static link NEW(int v, link next) {
	link x = malloc(sizeof(*x));
	x->v = v;
	x->next = next;
	return x;
}

void graphInit(int S) {
	int i;

	// Allocate memory for array of lists
	adj = malloc(S * sizeof(link));
	
	// Initalize values to zero
	for (i = 0; i < S; ++i) {
		adj[i] = NULL;
	}
}

void graphSet(int i, int j) {
	adj[i] = NEW(j, adj[i]);
	adj[j] = NEW(i, adj[j]);
}

void graphPrint(int i) {
	link t;

	for (t = adj[i]; t != NULL; t = t->next) {
		printf("%i ", t->v);
	}
}
