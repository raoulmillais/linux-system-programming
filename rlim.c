#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (void)
{
	struct rlimit rlim;
	int ret;

	ret = getrlimit (RLIMIT_FSIZE, &rlim);
	if (ret == -1) {
		perror ("getrlimit");
		return 1;
	}

	printf ("File size resource soft limit is %ld and hard limit is %ld\n",
			rlim.rlim_cur,
			rlim.rlim_max);

	return 0;
}
