#include <stdio.h>
#include <stdlib.h>

void out (void)
{
	printf ("atexit() succeeded!\n");
}


int main (void)
{
	if (atexit (out)) {
		fprintf (stderr, "atexit(0 failed!\n");
		return 1;
	}

	return 0;
}
