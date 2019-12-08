CC 			= gcc
CFLAGS		= -std=c99 -Wall -Werror
LIBS		=
TESTHEADER 	= minunit.h
SOURCES 	= $(filter-out $(wildcard test_*.c), $(wildcard *.c))
TESTSOURCES = $(patsubst %.c, test_%.c, ${SOURCES})
TESTSO		= $(patsubst %.c, %.o, ${TESTSOURCES})
OBJS 		= $(patsubst %.c, %.o, $(filter-out ${TESTSOURCES}, ${SOURCES}))
TESTS		= $(patsubst %.o, %.out, ${TESTSO})

.PHONY: all clean

all: ${TESTS}

test_%.out: %.o test_%.o
	${CC} $^ -o $@ ${LIBS}

test_%.o: test_%.c ${TESTHEADER}
	${CC} ${CFLAGS} -c $<

${OBJS}: %.o: %.c %.h
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out

verbose:
	-@echo "TEST SOURCES: "${TESTSOURCES}
	-@echo "TEST OBJS: "${TESTSO}
	-@echo "TESTS: "${TESTS}
	-@echo "SOURCES: "${SOURCES}
	-@echo "OBJS: "${OBJS}
