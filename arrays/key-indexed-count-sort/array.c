#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "array.h"

void array_randinit(item *a, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		a[i] = item_rand();
	}
}

void array_show(item *a, int l, int r) {
	int i;
	
	for (i = l; i <= r; ++i) {
		item_show(a[i]);
	}
	
	printf("\n");
}

void array_sort(item *a, int l, int r) {
	int M = 3;
	int i, j, cnt[M];
	item b[100];
	
	for (j = 0; j < M; ++j)
		cnt[j] = 0;
	
	for (i = l; i <= r; ++i)
		cnt[key(a[i])+1]++;
	
	for (j = 1; j < M; ++j)
		cnt[j] += cnt[j-1];
	
	for (i = l; i <= r; ++i)
		b[cnt[key(a[i])]++] = a[i];
	
	for (i = l; i <= r; ++i)
		a[i] = b[i-l];
}
