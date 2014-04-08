#include <stdio.h>
#include <sched.h>

int main (void)
{
	int policy;

	policy = sched_getscheduler (0);

	switch (policy) {
		case SCHED_OTHER:
			printf ("policy is normal\n");
			break;
		case SCHED_RR:
			printf ("policy is round-robin\n");
			break;
		case SCHED_FIFO:
			printf ("policy is first-in, first-out\n");
			break;
		case -1:
			perror ("sched_getscheduler");
			break;
		default:
			fprintf (stderr, "Unknown policy!\n");
	}

	return 0;
	
}
