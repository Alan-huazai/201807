SOURCES:=$(wildcard *.c)
CFLAGS:=-g -Wall
CC:=gcc
OBJS:= $(patsubst %.c,%.o,$(SOURCES))
main: $(OBJS)
	$(CC) $^ -o $@
clean:
	rm -f $(OBJD) main
