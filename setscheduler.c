#include <stdio.h>
#include <sched.h>

int main (void)
{
	int policy;
	struct sched_param sp = { .sched_priority = 1 };
	struct timespec tp;
	int ret;

	ret = sched_setscheduler (0, SCHED_RR, &sp);
	if (ret == -1) {
		perror ("sched_setscheduler");
		return 1;
	}

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

	ret = sched_getparam (0, &sp);
	if (ret == -1) {
		perror ("sched_getparam");
		return 1;
	}

	printf ("Our priority is %d\n", sp.sched_priority);

	ret = sched_rr_get_interval (0, &tp);
	if (ret == -1) {
		perror ("sched_rr_get_interval");
		return 1;
	}

	printf ("Our time quantum is %.2lf milliseconds\n",
			(tp.tv_sec * 1000.0f) + (tp.tv_nsec / 1000000.0f));

	return 0;
}
