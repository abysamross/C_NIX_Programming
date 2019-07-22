CC = cc
FEATURES = -D_XOPEN_SOURCE
CFLAGS = -Wall -std=c99 ${FEATURES}
LIB = 
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, ${SOURCES})
BINS = cnt.out locnt.out
IOBJS = $(filter-out $(patsubst %.out, %.o, ${BINS}), ${OBJS})

.PHONY: all clean help

all: ${BINS}

%.out:  ${IOBJS} %.o
	${CC} $^ ${LIB} -o $@


%.o: %.c mheader.h
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out

help:
	-@echo ${OBJS}
	-@echo ${IOBJS}

