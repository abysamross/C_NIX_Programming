CC 		 = gcc
CFLAGS   = -Wall -std=c99
LIBS	 = 
HEADERS  = $(wildcard *.h)
SOURCES  = $(wildcard *.c)
OSOURCES = mbst.c
OBJS	 = $(patsubst %.c, %.o, ${OSOURCES})
ESOURCES = $(filter-out ${OSOURCES}, ${SOURCES})
EXECS    = $(patsubst %.c, %.out, ${ESOURCES})

.PHONY: all clean

all: ${EXECS} ${OBJS}

%.out: ${OBJS} %.c
	${CC} ${CFLAGS} $^ ${LIB} -o $@ 

${OBJS}: %.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< 

clean:
	-@rm -rf *.o *.out
