#include <stdio.h>
#include <stdlib.h>

void print_chars (int n, char c)
{
	int i;

	for (i = 0; i < n; i++) {
		char *s;
		int j;

		s = calloc (i + 2, 1);
		if (!s) {
			perror ("calloc");
			exit(1);
		}

		for (j = 0; j < i + 1; j++) {
			s[j] = c;
		}

		printf ("%s\n", s);

		free (s);
	}
}

int main (void)
{
	print_chars (5, 'X');
	return 0;
}
