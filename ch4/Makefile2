.PONEY: all clean

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c, %, $(SRCS))
CFALGS = -Wall -Werror

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)