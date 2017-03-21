#include <stdio.h>
#include <stdlib.h>
#include "item.h"

item item_rand(void) {
	return rand() % 100;
}

item item_dummy(void) {
	return 0;
}

void item_show(item x) {
	printf("%i ", x);
}
