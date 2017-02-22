#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void) {
	
	int *a = malloc(N * sizeof(int));
	if (a == NULL) {
		printf("Insufficient memory.\n");
		return 0;
	}
	
	return 0;
}
