#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>

#define MAX_CPU 8

int main (void)
{
	cpu_set_t set;
	int ret, i;

	CPU_ZERO (&set);
	CPU_SET (0, &set);
	CPU_CLR (1, &set);
	ret = sched_setaffinity (0, sizeof (cpu_set_t), &set);
	if (ret == -1) {
		perror ("sched_setaffinity");
		return -1;
	}

	for (i = 0; i < MAX_CPU; i++) {
		int cpu;

		cpu = CPU_ISSET (i, &set);
		printf ("cpu=%i is %s\n", i,
				cpu ? "set" : "unset");
	}

	return 0;
}
