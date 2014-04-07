#include <unistd.h>
#include <sys/uio.h>
#include <errno.h>

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
