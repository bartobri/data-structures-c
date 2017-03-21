#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "array.h"

#define SW 1

static int N = 20;

int main(void) {
	item *a = malloc(N * sizeof(item));
	
	srand(time(NULL));

	array_randinit(a, N);

	array_show(a, 0, N-1);
	
	array_sort(a, 0, N-1);
	
	array_show(a, 0, N-1);
	
	return 0;
}
