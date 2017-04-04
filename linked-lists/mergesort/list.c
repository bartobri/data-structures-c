#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

link NEW(item key, link next) {
	link x = malloc(sizeof(*x));
	x->key = key;
	x->next = next;
	return x;
}

link list_max(link h) {
	link r;
	
	for (r = h; h->next != NULL; h = h->next) {
		if (item_less(r->next->key, h->next->key)) {
			r = h;
		}
	}
	
	return r;
}

link list_init(int N) {
	int i;
	link x;
	
	x = NEW(item_rand(), NULL);

	for (i = 1; i < N; ++i) {
		x = NEW(item_rand(), x);
	}
	
	x = NEW(item_dummy(), x);
	
	return x;
}

void list_show(link h) {
	
	for (; h->next != NULL; h = h->next) {
		item_show(h->next->key);
	}
	
	printf("\n");
}

////////////////////////
// MERGESORT ALGORITHMS
////////////////////////

link list_merge(link a, link b) {
	struct node head;
	link c = &head;
	
	while ((a != NULL) && (b != NULL)) {
		if (item_less(a->key, b->key)) {
			c->next = a;
			c = a;
			a = a->next;
		} else {
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	c->next = (a == NULL) ? b : a;
	
	return head.next;
}

link list_mergesort(link c) {
	link a, b;
	
	if (c == NULL || c->next == NULL)
		return c;
	
	a = c;
	b = c->next;
	
	while ((b != NULL) && (b->next != NULL)) {
		c = c->next;
		b = b->next->next;
	}
	
	b = c->next;
	c->next = NULL;
	
	return list_merge(list_mergesort(a), list_mergesort(b));
}
