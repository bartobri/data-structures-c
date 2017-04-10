#include <stdlib.h>
#include "Item.h"
#include "pq.h"

struct PQnode {
	Item key;
	PQlink prev, next;
};

struct pq {
	PQlink head, tail;
};

PQ PQinit(void) {
	PQ q = malloc(sizeof(*q));
	PQlink h = malloc(sizeof(*h));
	PQlink t = malloc(sizeof(*t));
	
	h->prev = t;
	h->next = t;
	
	t->prev = h;
	t->next = h;
	
	q->head = h;
	q->tail = t;
	
	return q;
}

int PQempty(PQ q) {
	return q->head->next->next == q->head;
}

PQlink PQinsert(PQ q, Item v) {
	PQlink t = malloc(sizeof(*t));
	t->key = v;
	t->next = q->head->next;
	t->next->prev = t;
	t->prev = q->head;
	q->head->next = t;
	return t;
}

Item PQdelmax(PQ q) {
	Item max;
	PQlink t;
	PQlink x = q->head->next;
	
	for (t = x; t->next != q->head; t = t->next) {
		if (less(x->key, t->key)) {
			x = t;
		}
	}
	
	max = x->key;
	x->next->prev = x->prev;
	x->prev->next = x->next;
	
	free(x);
	
	return max;
}

void PQchange(PQ q, PQlink x, Item v) {
	x->key = v;
}

void PQdelete(PQ q, PQlink x) {
	x->next->prev = x->prev;
	x->prev->next = x->next;
	
	free(x);
}

void PQjoin(PQ a, PQ b) {
	a->tail->prev->next = b->head->next;
	b->head->next->prev = a->tail->prev;
	a->head->prev = b->tail;
	b->tail->next = a->head;
	free(a->tail);
	free(b->head);
}

void PQdestroy(PQ q) {
	PQlink t = q->head->next;

	while (t->next != q->head) {
		PQdelete(q, t);
		t = q->head->next;
	}
	
	free(q->head);
	free(q->tail);
	free(q);
}

void PQcopy(PQ a, PQ b) {
	PQlink t;

	// Delete all links (if any) in b
	for (t = b->head->next; t->next != b->head; t = b->head->next) {
		PQdelete(b, t);
	}
	
	// Loop over a, inserting keys in to b
	for (t = a->head->next; t->next != a->head; t = t->next) {
		PQinsert(b, t->key);
	}
}
