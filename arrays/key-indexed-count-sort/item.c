#include <stdio.h>
#include <stdlib.h>
#include "item.h"

item item_rand(void) {
	switch (rand() % 3) {
		case 0:
			return 'a';
		case 1:
			return 'b';
		case 2:
			return 'c';
	}
}

void item_show(item x) {
	printf("%c ", x);
}
