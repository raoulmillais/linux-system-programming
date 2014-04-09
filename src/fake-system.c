#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int my_system (char *command)
{
	int fd, execret, status;
	pid_t pid, waited_pid;
	char *argv[4];

	if (command == NULL) {
		fd = open ("/bin/sh", O_RDONLY);
		if (fd < 0) {
			perror ("open");
			return 0;
		}

		fprintf(stderr, "Command was NULL\n");
		return -1;
	}

	pid = fork ();
	if (pid < 0) {
		 perror("fork");
		 return -1;
	}

	if (!pid) {
		/* Child process */
		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = command;
		argv[3] = NULL;

		execret = execvp ("sh", argv);
		if (execret < 0) {
			perror ("exec");
			return execret;
		}
	}

	waited_pid = wait(&status);
	if (waited_pid == -1) {
		perror ("wait");
		return -1;
	}

	if (WIFEXITED (status))
		return status;

	return -1;
}

int main (void)
{
	return my_system("echo foo");
}
