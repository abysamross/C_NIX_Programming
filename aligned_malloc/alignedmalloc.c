#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

//memory descriptor for aligned memory
struct Amem {
	long size;
	long alignBytes;
	void* address;
	void* alignedAdd;
};

//converting & checking cmdline arguments
long checkNum(char* arg) {

	char* endptr=NULL;
	long number;

	number = strtol(arg, &endptr, 10);

	if(*endptr) {

		if(endptr==arg && !number)
			fprintf(stderr, "Invalid value: %s\n", arg);
		else
			fprintf(stderr, "Invalid characters present at: %p, for: %s\n", endptr, arg);

		return -1; } return number;
}

//obtain aligned memory
void* getAlignedMem(struct Amem* s) {

	int mask;

	mask = ~(s->alignBytes-1);

	s->size +=  s->alignBytes;
	s->address = malloc(s->size);

	if(!s->address)
		return NULL;

	s->alignedAdd = (void*)(((uintptr_t)s->address & mask) + s->alignBytes);
	return s->alignedAdd;
}

//free aligned memory
void freeAlignedMem(struct Amem* s) {
	free(s->address);
}

int main(int argc, char** argv) {

	void* address = NULL;
	void* alignedAdd = NULL;

	long alignBytes=0;
	long size=0;

	struct Amem amem;

	time_t cur_time;
	char timeString[9];
	struct tm* time_info;

	//check usage
	if(argc<3) {
		printf("Usage! %s <number of bytes> <alignment bytes (pwr of 2)>\n", argv[0]);
		return 0;
	}

	//convert cmdline args 
	size = checkNum(argv[1]);
	alignBytes = checkNum(argv[2]);

	if(size==-1 || alignBytes==-1)
		return 1;

	//check if requested alignment is a power of 2 
	if(alignBytes & (alignBytes-1)) {
		fprintf(stderr, "# bytes for alignment: 0x%lx, is not a power of 2\n", alignBytes);
		return 1;
	}

	//populate the aligned memory descriptor
	amem.size = size;
	amem.alignBytes = alignBytes; 
	amem.address = address;
	amem.alignedAdd = alignedAdd;

	printf("Requested memory size: %ld\nRequested alignment: 0x%lx\n\n", size, alignBytes);

	//obtain aligned memory
	alignedAdd = getAlignedMem(&amem);

	if(!alignedAdd) {
		fprintf(stderr, "getting 0x%lx aligned memory failed\n", alignBytes);
		return 1;
	}

	printf("Allocated memory size: %ld\nUnaligned address obtained from malloc: %p\nAligned address: %p\n\n",
		amem.size, amem.address, amem.alignedAdd);

	//obtain local time
	time(&cur_time);
	time_info = localtime(&cur_time);
	strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

	printf("Copying local time into 0x%lx aligned address %p\n", alignBytes, amem.alignedAdd);

	//copy local time to aligned memory
	strncpy((char* )alignedAdd, timeString, size-1);
	((char*)alignedAdd)[size-1] = '\0';

	printf("local time: %s, copied local time: %s\n", timeString, (char*)alignedAdd);

	//free aligned memory
	freeAlignedMem(&amem);
	return 0;
}
