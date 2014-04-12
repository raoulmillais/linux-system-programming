CC=gcc
CFLAGS?=-Wall -Werror -g
AWK?=awk
SORT?=sort
PR?=pr
VPATH?=src

# daemon not included yet due to undefined NR_COUNT compiler error
SOURCES=atexit-example block-count custom-pidof fake-system filesize filetype
SOURCES+=getaffinity getscheduler getsid-example map-example naive_writev
SOURCES+=poll-example print-inode readv rlim schedulerpriorities select-example
SOURCES+=setaffinity setscheduler wait-example writev daemon find-file-in-dir
SOURCES+=eject inotify-q-size

all: $(SOURCES) thread

$(SOURCES): %: %.c
	$(CC) $(CFLAGS) $< -o out/$@

thread: thread-example.c
	$(CC) $(CFLAGS) -pthread $< -o out/$@

.PHONY: clean
clean:
	rm -f out/*

.PHONY: help
help:
	@$(MAKE) --print-data-base --question |           \
	$(AWK) '/^[^.%][-A-Za-z0-9_]*:/                  \
	        { print substr($$1,1,length($$1)-1) }' | \
	$(SORT) |                                        \
	$(PR) --omit-pagination --width=80 --columns=4
