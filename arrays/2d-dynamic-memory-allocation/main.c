#include <stdio.h>
#include <stdlib.h>

int **malloc2d(int r, int c) {
	int l;
	int **t = malloc(r * sizeof(int *));
	
	for (l = 0; l < r; ++l) {
		t[i] = malloc(c * sizeof(int));
	}
	
	return t;
}

int main(void) {
	int l, j, k;
	int x = 10;
	int y = 10;
	int z = 10;

	// Testing 2d allocation
	int **t = malloc2d(y, x);
	for (l = 0; l < y; ++l) {
		for (j = 0; j < x; ++j) {
			t[l][j] = 1;
		}
	}
	printf("2d Success\n");
	
	return 0;
}
