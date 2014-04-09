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

.PHONY: help
help:
	$(MAKE) --print-data-base --question | \
	awk '/^[^.%][-A-Za-z0-9_]*:/{ print substr($$1,1,length($$1)-1) }' | \
	sort | \
	pr --omit-pagination --width=80 --columns=4
