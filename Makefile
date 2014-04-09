CC=gcc
CFLAGS=-Wall -Werror -g
VPATH=src

# daemon not included yet due to undefined NR_COUNT compiler error
SOURCES=atexit-example block-count custom-pidof fake-system filesize filetype \
getaffinity getscheduler getsid-example map-example naive_writev poll-example \
print-inode readv rlim schedulerpriorities select-example setaffinity \
setscheduler wait-example writev

all: $(SOURCES) thread

$(SOURCES): %: %.c
	$(CC) $(CFLAGS) $< -o out/$@

thread: thread-example.c
	$(CC) $(CFLAGS) -pthread $< -o out/$@

.PHONY: clean
clean:
	rm -f out/*
