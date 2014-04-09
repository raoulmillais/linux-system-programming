#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>

ssize_t naive_writev (int fd, const struct iovec *iov, int count)
{
	ssize_t ret = 0;
	int i;

	for (i = 0; i < count; i++) {
		ssize_t nr;

		errno = 0;
		nr = write (fd, iov[i].iov_base, iov[i].iov_len);
		if (nr == -1) {
			if (errno == EINTR)
				continue;

			ret = -1;
			break;
		}
		ret += nr;
	}

	return ret;
}

int main ()
{
	struct iovec iov[3];
	ssize_t nr;
	int fd, i;

	char *buf[] = {
		"The term buccaneer comes from the word boucan.\n",
		"A boucan is a wooden frame used for cooking meat.\n",
		"Buccaneer is the West Indies name for a pirate.\n" };

	fd = open ("bucaneer.txt", O_WRONLY| O_CREAT | O_TRUNC);
	if (fd == -1) {
		perror ("open");
		return 1;
	}

	for (i = 0; i < 3; i++) {
		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen (buf[i]) + 1;
	}

	nr = naive_writev (fd, iov, 3);
	if (nr == -1) {
		perror ("writev");
		return 1;
	}
	printf("wrote %ld bytes\n", nr);

	if (close (fd)) {
		perror ("close");
		return 1;
	}

	return 0;
}
