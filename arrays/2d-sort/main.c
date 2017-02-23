#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10   // max words in array
#define WMAX 100  // max length of word

int compare(const void *i, const void *j) {
	return strcmp(*(char **)i, *(char **)j);
}

int main(void) {
	int i;
	char *(a[NMAX]);
	char buf[WMAX];
	
	for (i = 0; i < NMAX; ++i) {
		a[i] = NULL;
	}
	
	for (i = 0; i < NMAX; ++i) {
		if ((scanf("%s", buf)) == EOF) {
			break;
		}
		a[i] = malloc(strlen(buf));
		strcpy(a[i], buf);
		printf("%i -> %s\n", i, a[i]);
	}
	
	qsort(a, i, sizeof(char *), compare);
	
	for (i = 0; a[i] != NULL; ++i) {
		printf("%i -> %s\n", i, a[i]);
	}
	
	return 0;
}
