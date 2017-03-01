#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static int N;
static int tail;
static int head;

void QUEUEinit(int maxN) {
	q = malloc(maxN * sizeof(Item));
	N = maxN;
	head = N;
	tail = 0;
}

int QUEUEempty(void) {
	return head % N == tail;
}

void QUEUEput(Item item) {
	q[tail++] = item;
	tail = tail % N;
}

Item QUEUEget(void) {
	head = head % N;
	return q[head++];
}
