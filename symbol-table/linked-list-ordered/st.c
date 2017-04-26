#include <stdlib.h>
#include "st.h"

typedef struct STnode *link;
struct STnode {
	Item item;
	link next;
};

static link head, z;
static int N;

static link NEW(Item item, link next) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

void STinit(int max) {
	N = 0;
	head = (z = NEW(NULLitem, NULL));
}

int STcount(void) {
	return N;
}

void STinsert(Item item) {
	link x;

	if (head == z || less(item, head->item)) {
		head = NEW(item, head);
		++N;
		return;
	}

	for (x = head; x->next != z; x = x->next) {
		if (less(item, x->next->item)) {
			break;
		}
	}

	x->next = NEW(item, x->next);

	++N;
}

Item STsearchR(link t, Key v) {
	if (t == z) {
		return NULLitem;
	}

	if (eqkey(t->item->key, v)) {
		return t->item;
	}
	
	return STsearchR(t->next, v);
}

Item STsearch(Key v) {
	return STsearchR(head, v);
}

void STdelete(Item item) {
	link x, t;
	
	if (eq(head->item, item)) {
		t = head;
		head = head->next;
		free(t);
		--N;
		return;
	}
	
	for (x = head; x->next != NULL; x = x->next) {
		if (eq(x->next->item, item)) {
			t = x->next;
			x->next = t->next;
			free(t);
			--N;
			return;
		}
	}
}

Item STselect(int k) {
	link x;
	
	for (x = head; x != z; x = x->next) {
		if (--k == 0) {
			return x->item;
		}
	}

	return NULLitem;
}

void STsort(void (*visit)(Item)) {
	link x;
	
	for (x = head; x != z; x = x->next) {
		visit(x->item);
	}
}
