#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static int N, head, tail;

void QUEUEinit(int maxN) {
	q = malloc(maxN * sizeof(Item));
	N = maxN;
	head = N - 1;
	tail = 0;
}

int QUEUEempty(void) {
	return head % N == tail;
}

void QUEUEputtail(Item item) {
	q[tail++] = item;
	tail = tail % N;
}

void QUEUEputhead(Item item) {
	q[head] = item;
	
	if (head == 0)
		head = N - 1;
	else
		--head;
}

Item QUEUEgethead(void) {
	head = (head + 1) % N;
	return q[head];
}

Item QUEUEgettail(void) {
	if (tail == 0)
		tail = N - 1;
	else
		--tail;
	
	return q[tail];
}
