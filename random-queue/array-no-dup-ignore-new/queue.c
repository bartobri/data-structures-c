#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static Item *r;
static int N;
static int c;

void QUEUEinit(int maxN) {
	int i;
	
	q = malloc(maxN * sizeof(Item));
	r = malloc(maxN * sizeof(int));
	N = maxN;
	c = 0;
	
	for (i = 0; i < N; ++i) {
		r[i] = 0;
	}
}

int QUEUEempty(void) {
	return c;
}

void QUEUEput(Item item) {
	int t;
	
	for (t = 0; t < N; ++t) {
		if (q[t] == item) {
			return;
		}
	}
	
	for (t = rand() % N; r[t] > 0; t = (t + 1) % N)
		;

	q[t] = item;
	r[t] = 1;
	
	++c;
}

Item QUEUEget(void) {
	int t;
	
	for (t = rand() % N; r[t] == 0; t = (t + 1) % N)
		;

	r[t] = 0;
	--c;

	return q[t];
}
