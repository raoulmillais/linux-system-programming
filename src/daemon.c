#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <linux/limits.h>
/*
 *On my system linux/fs.h undefs NR_OPEN and linux/limits.h defines it.
 *No matter whether I include limits after fs or not gcc errors with a warning
 *saying NR_OPEN is undefined (gcc 4.8.2 / kernel 3.13.8-1-ARCH) so we must
 *define it here
 */
#define NR_OPEN 1024

int main (void)
{
	pid_t pid;
	int i;

	/* create new process */
	pid = fork ();
	if (pid == -1) {
		return -1;
	} else if (pid != 0) {
		exit (EXIT_SUCCESS);
	}

	if (setsid () == -1) {
		return -1;
	}

	if (chdir ("/") == -1) {
		return -1;
	}

	for (i = 0; i < NR_OPEN; i++)
		close (i);

	open ("/dev/null", O_RDWR);
	dup (0);
	dup (0);

	return 0;
}
