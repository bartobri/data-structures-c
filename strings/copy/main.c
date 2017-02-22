#include <stdio.h>

int my_strcpy(char *a, char *b);

int main(void) {
	char a[15];
	char *b = "This is a test";
	int l;
	
	l = my_strcpy(a, b);
	
	printf("%i chars copied\n", l);
	printf("%s\n", a);
	
	return 0;
}

// Copy b (src) to a (dst)
int my_strcpy(char *a, char *b) {
	int i;
	
	for (i = 0; (a[i] = b[i]) != 0; ++i)
		;
	
	return i;
}
