#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler (int signo) 
{
	/* We shouldn't be using printf here because of reentrancy. */
	printf("Caught %s\n", sys_siglist[signo]);
	exit (EXIT_SUCCESS);
}

int main (void)
{
	if (signal (SIGINT, signal_handler) == SIG_ERR) {
		fprintf (stderr, "Cannot handle SIGINT\n");
		exit (EXIT_FAILURE);
	}

	if (signal (SIGTERM, signal_handler) == SIG_ERR) {
		fprintf (stderr, "Cannot handle SIGTERM\n");
		exit (EXIT_FAILURE);
	}

	kill (getpid (), SIGINT);
	/* or we could do this but we won't reach here */
	raise (SIGTERM);

	return 0;
}
