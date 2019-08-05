CC = gcc
CFLAGS = -Wall -std=c99
LIBS = 
SOURCES = $(wildcard *stack*.c)
OBJS = $(patsubst %.c, %.o, ${SOURCES})

.PHONY: all clean

all: ${OBJS}

%.o: %.c %.h
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
