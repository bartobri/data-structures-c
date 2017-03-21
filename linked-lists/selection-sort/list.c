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
	link max, t, out = NULL;
	
	while (h->next != NULL) {
		max = list_max(h);
		t = max->next;
		max->next = t->next;
		t->next = out;
		out = t;
	}
	
	h->next = out;
	
	return h;
}
