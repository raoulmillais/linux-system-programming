#include <unistd.h>
#include <stdio.h>
// On my system the inotify header is in sys unlike in the book
#include <sys/inotify.h>
#include <sys/types.h>
#include <sys/ioctl.h>
// The attributed form in the book wouldn't work for me and was missing
// the constants needed to initialise the buffers.
// Love's article on linuxjournal provides the necessary info:
// http://www.linuxjournal.com/article/8478?page=0,1
#define NAME_MAX 16
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE  + NAME_MAX))

int main (void)
{
	unsigned int queue_len;
	int ret, fd;
	char buf[BUF_LEN];
	ssize_t len, i = 0;

	fd = inotify_init ();
	if (fd < 0) {
		perror ("inotify_init");
		return 1;
	}

	ret = inotify_add_watch (fd, "./", IN_ACCESS | IN_MODIFY);
	if (ret < 0) {
		perror ("inotify_add_watch");
		return 1;
	}

	len = read (fd, buf, BUF_LEN);
	while (i < len)	{
		struct inotify_event *event =
			(struct inotify_event *) &buf[i];

		printf ("wd=%d mask=%d cookie=%d len=%d dir=%s\n",
				event->wd, event->mask, event->cookie, event->len,
				(event->mask & IN_ISDIR) ? "yes" : "no");

		if (event->len) {
			printf ("name=%s\n", event->name);
		}

		i += sizeof (struct inotify_event) + event->len;
	}


	ret = ioctl (fd, FIONREAD, &queue_len);
	if (ret < 0) {
		perror ("ioctl");
		return 1;
	}

	printf ("%u bytes pending in queue\n", queue_len);

	ret = close (fd);
	if (fd == -1) {
		perror ("close");
		return 1;
	}

	return 0;
}
