CC = cc
CFLAGS = -Wall -std=c99 
LIB = 
SOURCES = ${wildcard *.c}
OBJS = ${patsubst %.c, %.o, ${SOURCES}}
BINS = ${patsubst %.o, %.out, ${OBJS}}

.PHONY: all clean

all: ${BINS}

%.out: %.o
	${CC} $< ${LIB} -o $@


%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
