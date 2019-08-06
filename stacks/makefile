CC = gcc
CFLAGS = -Wall -std=c99
LIBS = 
SOURCES = $(wildcard *.c)
OSOURCES = mstack.c
ESOURCES = $(filter-out ${OSOURCES}, ${SOURCES})
OBJS = $(patsubst %.c, %.o, ${OSOURCES})
EXECS = $(patsubst %.c, %.out, ${ESOURCES})

.PHONY: all clean

all: ${EXECS} ${OBJS}
	
%.out: ${OBJS} %.c
	${CC} ${CFLAGS} $^ -o $@

${OBJS}: %.o: %.c %.h
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
