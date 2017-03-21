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

link list_sort(link h) {
	link x, u, t, out;
	
	out = NEW(item_dummy(), NULL);
	
	for (t = h->next; t != NULL; t = u) {
		u = t->next;
		for (x = out; x->next != NULL; x = x->next) {
			if (item_less(t->key, x->next->key)) {
				break;
			}
		}
		t->next = x->next;
		x->next = t;
		
	}
	
	return out;
}
