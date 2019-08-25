CC 				= cc
ELFPROC			= objdump
ELFPROCFLAGS	= -dx
CFLAGS 			= -O0
SOURCES 		= $(wildcard *.c)
#PREPROCS 		= $(patsubst %.c, %.i, ${SOURCES})
COMPS 			= $(patsubst %.c, %.s, ${SOURCES})
ASMS  			= $(patsubst %.s, %.o, ${COMPS})
ELFS			= $(patsubst %.o, %.d, ${ASMS})

.PHONY = all clean

all: ${ELFS} ${ASMS} ${COMPS} ${PREPROCS}

%.d: %.o
	${ELFPROC} ${ELFPROCFLAGS} $< > $@	

%.o: %.s
	${CC} ${CFLAGS} -c $<

%.s: %.c
	${CC} ${CFLAGS} -S $<

#%.i: %.c
#	${CC} -E $<

clean:
	-@rm -rf *.o *.out *.i *.s
