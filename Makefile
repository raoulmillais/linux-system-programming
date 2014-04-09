CC=gcc
CFLAGS=-Wall -Werror -g

atexit-example: src/atexit-example.c
	$(CC) $(CFLAGS) -o out/atexit-example src/atexit-example.c

block-count: src/block-count.c
	$(CC) $(CFLAGS) -o out/block-count src/block-count.c

custom-pidof: src/custom-pidof.c
	$(CC) $(CFLAGS) -o out/custom-pidof src/custom-pidof.c

daemon: src/daemon.c
	$(CC) -o out/daemon src/daemon.c

fake-system: src/fake-system.c
	$(CC) $(CFLAGS) -o out/fake-system src/fake-system.c

filesize: src/filesize.c
	$(CC) $(CFLAGS) -o out/filesize src/filesize.c

filetype: src/filetype.c
	$(CC) $(CFLAGS) -o out/filetype src/filetype.c

getaffinity: src/getaffinity.c
	$(CC) $(CFLAGS) -o out/getaffinity src/getaffinity.c

getscheduler: src/getscheduler.c
	$(CC) $(CFLAGS) -o out/getscheduler src/getscheduler.c

getsid-example: src/getsid-example.c
	$(CC) $(CFLAGS) -o out/getsid-example src/getsid-example.c

map-example: src/map-example.c
	$(CC) $(CFLAGS) -o out/map-example src/map-example.c

naive_writev: src/naive_writev.c
	$(CC) $(CFLAGS) -o out/naive_writev src/naive_writev.c

poll-example: src/poll-example.c
	$(CC) $(CFLAGS) -o out/poll-example src/poll-example.c

print-inode: src/print-inode.c
	$(CC) $(CFLAGS) -o out/print-inode src/print-inode.c

readv: src/readv.c
	$(CC) $(CFLAGS) -o out/readv src/readv.c

rlim: src/rlim.c
	$(CC) $(CFLAGS) -o out/rlim src/rlim.c

schedulerpriorities: src/schedulerpriorities.c
	$(CC) $(CFLAGS) -o out/schedulerpriorities src/schedulerpriorities.c

select-example: src/select-example.c
	$(CC) $(CFLAGS) -o out/select-example src/select-example.c

setaffinity: src/setaffinity.c
	$(CC) $(CFLAGS) -o out/setaffinity src/setaffinity.c

setscheduler: src/setscheduler.c
	$(CC) $(CFLAGS) -o out/setscheduler src/setscheduler.c

thread-example: src/thread-example.c
	$(CC) $(CFLAGS) -pthread -o out/thread-example src/thread-example.c

wait-example: src/wait-example.c
	$(CC) $(CFLAGS) -o out/wait-example src/wait-example.c

writev: src/writev.c
	$(CC) $(CFLAGS) -o out/writev src/writev.c

all: atexit-example block-count custom-pidof fake-system filesize filetype getaffinity getscheduler getsid-example map-example naive_writev poll-example print-inode readv rlim schedulerpriorities select-example setaffinity setscheduler thread-example wait-example writev
