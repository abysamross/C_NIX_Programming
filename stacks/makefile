CC = gcc
CFLAGS = -Wall -std=c99
LIBS = 
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, ${SOURCES})
EXECS = stack.out

.PHONY: all clean

all: ${OBJS}

%.o: %.c %.h
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
