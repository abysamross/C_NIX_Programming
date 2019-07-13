CC = gcc
LIB = -lpthread
SOURCES = ${wildcard *c} 
OBJS = ${patsubst %.c, %.o, ${SOURCES}}
EXECS = ${patsubst %.c, %.out, ${SOURCES}}

.PHONY: all clean help

all: ${EXECS}

%.out: %.o
	${CC} $< ${LIB} -o $@

%.o: %.c
	${CC} ${LIB} -c $<

clean:
	-@rm -rf *.o *.out ${EXECS}

help:
	-@echo "make: Compiles all files in PWD with pthread lib and creates <filename>.out in PWD"
	-@echo "make help: Prints this help message"
	-@echo "make clean: Removes all output files"
	-@echo ""
	-@echo "List of SOURCEs: "${SOURCES}
	-@echo "List of OBJs that would be created: "${OBJS}
	-@echo "List of EXEs that would be created: "${EXECS}
