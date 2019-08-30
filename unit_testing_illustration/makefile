CC 			= gcc
CFLAGS		= -std=c99 -Wall -Werror
LIBS		=
HEADERS 	= $(wildcard *.h)
SOURCES 	= $(wildcard *.c)
TESTSOURCES = $(filter $(wildcard test_*.c), ${SOURCES})
TESTSO		= $(patsubst %.c, %.o, ${TESTSOURCES})
OBJS 		= $(patsubst %.c, %.o, $(filter-out ${TESTSOURCES}, ${SOURCES}))
TEST		= test.out

.PHONY: all clean

all: ${TEST}

%.out: ${TESTSO} ${OBJS}
	${CC} $^ -o $@ ${LIBS}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out

help:
	-@echo ${TESTSOURCES} ${TESTSO} ${OBJS}
