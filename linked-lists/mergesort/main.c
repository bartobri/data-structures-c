#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "list.h"

static int N = 50;

int main(void) {
	link h;
	
	srand(time(NULL));

	h = list_init(N);
	
	list_show(h);
	
	h = list_mergesort(h);
	
	list_show(h);
	
	return 0;
}
