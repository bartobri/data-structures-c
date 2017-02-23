#include <stdio.h>
#include <stdlib.h>

int **malloc2d(int r, int c) {
	int i;
	int **t = malloc(r * sizeof(int *));
	
	for (i = 0; i < r; ++i) {
		t[i] = malloc(c * sizeof(int));
	}
	
	return t;
}

int main(void) {
	int i, j, k;
	int x = 10;
	int y = 10;
	int z = 10;

	// Testing 2d allocation
	int **t = malloc2d(y, x);
	for (i = 0; i < y; ++i) {
		for (j = 0; j < x; ++j) {
			t[i][j] = 1;
		}
	}
	printf("2d Success\n");
	
	return 0;
}
