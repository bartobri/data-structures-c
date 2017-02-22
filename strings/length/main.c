#include <stdio.h>

int my_strlen(const char *);

int main(void) {
	char *string = "This is a test";
	int l;
	
	l = my_strlen(string);
	
	printf("Length is %i\n", l);
	
	return 0;
}

int my_strlen(const char *s) {
	int i;
	
	for (i = 0; s[i] != 0; ++i)
		;
	
	return i;
}
