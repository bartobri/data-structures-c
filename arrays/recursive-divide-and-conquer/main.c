#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef int Item;

Item max(Item *, int, int);

int main(void) {
	int i;
	Item m, a[N];
	
	srand(time(NULL));

	for (i = 0; i < N; ++i) {
		a[i] = rand() % 1000;
	}
	
	m = max(a, 0, N-1);
	
	printf("Max array value is: %d\n", m);
	
	return 0;
}

Item max(Item a[], int l, int r) {
	Item u, v;
	int m = (l+r)/2;
	
	if (l == r)
		return a[l];
	
	u = max(a, l, m);
	v = max(a, m+1, r);
	
	if (u > v)
		return u;
	else
		return v;
}
