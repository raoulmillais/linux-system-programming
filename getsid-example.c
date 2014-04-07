#include <unistd.h>
#include <stdio.h>

int main (void)
{
	pid_t sid;

	sid = getsid (0);
	if (sid == -1) {
		perror ("getsid");
		return 1;
	}

	printf ("My session id=%d\n", sid);

	return 0;
}
