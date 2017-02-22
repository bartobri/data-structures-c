#include <stdio.h>

int my_strcmp(char *a, char *b);

int main(void) {
	char *a = "This is a test";
	char *b = "This is a test";
	int l;
	
	l = my_strcmp(a, b);
	
	printf("Return val: %i\n", l);
	
	return 0;
}

int my_strcmp(char *a, char *b) {
	int i;
	
	for (i = 0; a[i] == b[i]; ++i)
		if (a[i] == 0)
			return 0;
	
	return a[i] - b[i];
}
