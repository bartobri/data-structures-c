#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;
static int M;

void STACKinit(int maxN) {
	s = malloc(maxN * sizeof(Item));
	N = 0;
	M = maxN;
}

int STACKcount(void) {
	return N;
}

void STACKpush(Item item) {
	s[N++] = item;
}

Item STACKpop(void) {
	return s[--N];
}
