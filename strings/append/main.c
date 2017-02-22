#include <stdio.h>

void my_strcat(char *a, char *b);
int my_strcpy(char *a, char *b);
int my_strlen(const char *s);

int main(void) {
	char a[30] = {0};
	char *b = "This is a test";
	int l;
	
	my_strcat(a, b);
	
	printf("%s\n", a);
	
	my_strcat(a, b);
	
	printf("%s\n", a);
	
	return 0;
}

void my_strcat(char *a, char *b) {
	my_strcpy(a + my_strlen(a), b);
}

// Copy b (src) to a (dst)
int my_strcpy(char *a, char *b) {
	int i;
	
	for (i = 0; (a[i] = b[i]) != 0; ++i)
		;
	
	return i;
}

int my_strlen(const char *s) {
	int i;
	
	for (i = 0; s[i] != 0; ++i)
		;
	
	return i;
}
