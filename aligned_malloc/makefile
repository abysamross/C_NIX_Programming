CC = gcc
CFLAGS = 
SOURCES = ${wildcard *.c}
OBJS = ${patsubst %.c, %.o, ${SOURCES}}
EXECS = ${patsubst %.o, %.out, ${OBJS}}

.PHONY:  all clean

all: ${EXECS}

%.out: %.o
	${CC} $< ${CFLAGS} -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
