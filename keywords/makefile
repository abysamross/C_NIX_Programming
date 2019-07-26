CC = cc
CFLAGS = -O0 -m32
SOURCES = $(wildcard *.c)
PREPROCS = $(patsubst %.c, %.i, ${SOURCES})
ASM = $(patsubst %.c, %.s, ${SOURCES})

.PHONY = all clean

all: ${PREPROCS} ${ASM}

%.s: %.c
	${CC} ${CFLAGS} -S $<

%.i: %.c
	${CC} -E $<

clean:
	-@rm -rf *.o *.out *.i *.s
