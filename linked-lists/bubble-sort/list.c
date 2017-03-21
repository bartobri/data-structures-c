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

void list_compexch(link a, link b) {
	link t;
	if (item_less(b->next->key, a->next->key)) {
		t = b->next;
		b->next = b->next->next;
		t->next = b;
		a->next = t;
	}
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
	link x, t, out = NULL;
	
	while (h->next != NULL) {
		for (x = h; x->next != NULL; x = x->next) {
			if (x->next->next == NULL) {
				t = x->next;
				x->next = NULL;
				t->next = out;
				out = t;
				break;
			} else {
				list_compexch(x, x->next);
			}
		}
	}
	
	h->next = out;
	
	return h;
}
