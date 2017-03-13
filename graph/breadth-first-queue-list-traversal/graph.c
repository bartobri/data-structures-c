#include <stdlib.h>
#include <stdio.h>
#include "GRAPH.h"
#include "QUEUE.h"

typedef struct node *link;
struct node {
	int v;
	link next;
};
static link *adj;
static int *visited;

static link NEW(int v, link next) {
	link x = malloc(sizeof(*x));
	x->v = v;
	x->next = next;
	return x;
}

void graphInit(int S) {
	int i;

	adj = malloc(S * sizeof(link));
	
	for (i = 0; i < S; ++i) {
		adj[i] = NULL;
	}
	
	visited = malloc(S * sizeof(int));
	
	for (i = 0; i < S; ++i) {
		visited[i] = 0;
	}
}

void graphSet(int i, int j) {
	adj[i] = NEW(j, adj[i]);
	adj[j] = NEW(i, adj[j]);
}

void traverse(int k, void(*visit)(int)) {
	link t;

	QUEUEinit();
	QUEUEput(k);
	
	while (!QUEUEempty()) {
		k = QUEUEget();
		if (visited[k] == 0) {
			(*visit)(k);
			visited[k] = 1;
			for (t = adj[k]; t != NULL; t = t->next) {
				if (visited[t->v] == 0) {
					QUEUEput(t->v);
				}
			}
		}
	}
}
