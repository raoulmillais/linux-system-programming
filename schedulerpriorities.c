#include <stdio.h>
#include <sched.h>

int main (void)
{
	int min, max;

	min = sched_get_priority_min (SCHED_RR);
	if (min == -1) {
		perror ("sched_get_priority_min");
		return 1;
	}

	max = sched_get_priority_max (SCHED_RR);
	if (max == -1) {
		perror ("sched_get_priority_max");
		return 1;
	}

	printf ("SCHED_RR priority range is %d - %d\n", min, max);
	return 0;
}
