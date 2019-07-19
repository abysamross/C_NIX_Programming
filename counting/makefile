CC = cc
FEATURES = -D_XOPEN_SOURCE
CFLAGS = -Wall -std=c99 ${FEATURES}
LIB = 
SOURCES = ${wildcard *.c}
OBJS = ${patsubst %.c, %.o, ${SOURCES}}
BIN = cnt.out

.PHONY: all clean

all: ${BIN}

${BIN}: ${OBJS} 
	${CC} $^ ${LIB} -o $@


%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	-@rm -rf *.o *.out
