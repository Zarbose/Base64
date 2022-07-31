CC ?= gcc
CFLAGS ?= -Wall -Wextra
LDFLAGS ?=

objects := main.o strprocess.o load.o

.PHONY: clean

base64: $(objects)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

main.o: main.c strprocess.h variable.h load.h
	$(CC) $(CFLAGS) -c $<

strprocess.o: strprocess.c strprocess.h variable.h
	$(CC) $(CFLAGS) -c $<

load.o: load.c load.h variable.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(objects)