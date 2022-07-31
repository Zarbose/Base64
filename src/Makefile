CC ?= gcc
CFLAGS ?= -Wall -Wextra
LDFLAGS ?=

objects := main.o load.o

.PHONY: clean

base64: $(objects)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

main.o: main.c load.h
	$(CC) $(CFLAGS) -c $<

load.o: load.c load.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(objects)