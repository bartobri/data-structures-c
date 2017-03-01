#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

#define N 10

int main(int argc, char *argv[]) {
	STACKinit(N);
	
	STACKpush(1);
	STACKpush(2);
	STACKpush(3);
	STACKpush(2);
	STACKpush(4);
	printf("Popped %i\n", STACKpop());
	printf("Popped %i\n", STACKpop());
	printf("Popped %i\n", STACKpop());
	printf("Popped %i\n", STACKpop());
	
	return 0;
}
