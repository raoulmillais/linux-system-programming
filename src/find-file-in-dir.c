#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	struct dirent *entry;
	struct stat buf;
	int ret;
	DIR *dir;

	if (argc < 3) {
		fprintf (stderr, "Usage: %s <directory> <file>\n", argv[0]);
		return 1;
	}

	ret = stat (argv[1], &buf);
	if (ret < 0) {
		perror ("stat");
		return 1;
	}

	if (S_ISDIR(buf.st_mode)) {
		ret = 1;
		dir = opendir (argv[1]);

		errno = 0;
		while ((entry = readdir (dir)) != NULL) {
			if (strcmp (entry->d_name, argv[2]) == 0) {
				ret = 0;
				break;
			}
		}

		if (errno && !entry) {
			perror ("readdir");
			return 1;
		}

		closedir (dir);
		return ret;
	}

	fprintf(stderr, "%s is not a directory\n", argv[1]);
	return 1;
}
