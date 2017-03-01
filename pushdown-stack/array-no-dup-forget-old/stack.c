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
	int i;
	
	for (i = 0; i < N; ++i) {
		if (s[i] == item) {
			for (; i < N; ++i) {
				s[i] = s[i+1];
			}
			--N;
		}
	}
	
	s[N++] = item;
}

Item STACKpop(void) {
	return s[--N];
}
