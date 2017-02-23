#include <stdio.h>

int searchstr(char *, char *);

int main(void) {
	int r;
	char *big = "This is a big long string that will be used for searching smaller strings within.";
	char *small = "small";
	
	r = searchstr(big, small);
	
	if (r) {
		printf("String found at index %i\n", r);
	} else {
		printf("String not found\n");
	}
	
	return 0;
}
int searchstr(char *a, char *b) {
	int i, j;
	
	for (i = 0; a[i] != 0; ++i) {
		for (j = 0; b[j] != 0; ++j) {
			if (a[i+j] != b[j])
				break;
		}
		if (b[j] == 0)
			return i;
	}
	
	return 0;
}
