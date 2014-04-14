#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main (void)
{
	size_t requested = 21;
	size_t actual;
	char *buf;

	buf = malloc (requested);
	if (!buf) {
		perror ("malloc");
		return 1;
	}

	actual = malloc_usable_size (buf);

	printf ("%ld bytes actually available in buf\n", actual);

	return 0;
}
