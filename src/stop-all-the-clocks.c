#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	clockid_t clocks[] = {
		CLOCK_REALTIME,
		CLOCK_MONOTONIC,
		CLOCK_PROCESS_CPUTIME_ID,
		CLOCK_THREAD_CPUTIME_ID,
		CLOCK_MONOTONIC_RAW,
		(clockid_t) -1
	};
	int i, ret;
	time_t now;
	struct timeval time_of_day;

	printf ("Getting clock resolutions and times of various clocks:\n");

	for (i = 0; clocks[i] != -1; i++) {
		struct timespec res, ts;

		printf ("Clock: %d\n", clocks[i]);
		ret = clock_getres(clocks[i], &res);
		if (ret) {
			perror ("clock_getres");
			exit (EXIT_FAILURE);
		} else
			printf ("Resolution: sec=%ld nsec=%ld\n",
				res.tv_sec, res.tv_nsec);

		ret = clock_gettime(clocks[i], &ts);
		if (ret) {
			perror ("clock_gettime");
			exit (EXIT_FAILURE);
		} else
			printf ("Time: sec=%ld nsec=%ld\n",
				ts.tv_sec, ts.tv_nsec);
	}

	now = time (&now);
	if (now == -1) {
		/* This should only happen if &now is an invlid pointer */
		perror ("time");
		exit (EXIT_FAILURE);
	}

	printf ("Current time in seconds since the epoch: %ld\n", now);

	printf ("Getting more accurate time:\n");
	ret = gettimeofday (&time_of_day, NULL);
	if (ret == -1) {
		perror ("gettimeofday");
		exit (EXIT_FAILURE);
	}
	
	printf ("\tseconds=%ld, useconds=%ld\n",
			(long)time_of_day.tv_sec, (long)time_of_day.tv_usec);
	exit (EXIT_SUCCESS);
}
