#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	long hz;

	hz = sysconf (_SC_CLK_TCK);
	if (hz == -1) {
		perror ("sysconf");
		exit (EXIT_FAILURE);
	}

	printf ("There are %ld ticks per second\n", hz);
	exit (EXIT_SUCCESS);
}
