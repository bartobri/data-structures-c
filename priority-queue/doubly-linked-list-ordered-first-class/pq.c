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
	PQlink x;
	PQlink t = malloc(sizeof(*t));

	t->key = v;

	for (x = q->head->next; x->next != q->head; x = x->next) {
		if (less(x->key, v)) {
			break;
		}
	}
	
	t->next = x;
	t->prev = x->prev;
	x->prev->next = t;
	x->prev = t;
	return t;
}

Item PQdelmax(PQ q) {
	Item max;
	PQlink x = q->head->next;
	
	max = x->key;
	x->next->prev = x->prev;
	x->prev->next = x->next;
	
	free(x);
	
	return max;
}

void PQchange(PQ q, PQlink x, Item v) {
	PQlink t;
	
	x->key = v;
	x->next->prev = x->prev;
	x->prev->next = x->next;
	
	for (t = q->head->next; t->next != q->head; t = t->next) {
		if (less(t->key, x->key)) {
			break;
		}
	}
	
	x->next = t;
	x->prev = t->prev;
	t->prev->next = x;
	t->prev = x;
}

void PQdelete(PQ q, PQlink x) {
	x->next->prev = x->prev;
	x->prev->next = x->next;
	
	free(x);
}

void PQjoin(PQ a, PQ b) {
	PQlink t, ta, tb;
	
	for (tb = b->head->next; tb->next != b->head; tb = t) {
		for (ta = a->head->next; ta->next != a->head; ta = ta->next) {
			if (less(ta->key, tb->key)) {
				break;
			}
		}
		
		t = tb->next;
		
		tb->next = ta;
		tb->prev = ta->prev;
		ta->prev->next = tb;
		ta->prev = tb;
	}

	free(b->tail);
	free(b->head);
	free(b);
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
