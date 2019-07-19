#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include <string.h>
#include <libgen.h>

int debug = 0;
int correctness = 0; 
char* filename = NULL;
off_t chunkSize = 0;

#define NTHREADS 4 

//thread identifier and arguments
struct threadInfo {
	pthread_t thread;
	int tnum;
	off_t offset;
};

//thread fn
void* readFileChunk(void* args) {
	char* addr = NULL;
	long pageSize;
	long pageMask;
	int ret=1;
	int fd;
	int ofd;
	char* ifilename=NULL;
	char* ofilename=NULL;
	char* bname;
	size_t length;
	ssize_t w;
	off_t pAlignedOff;
	struct threadInfo* tInfo = args;

	//duplicate input filename
	ifilename = strndup(filename, strlen(filename));
	if(!ifilename) {
		perror("Error: copying input file name");
		goto quit;
	}

	//check for valid input file
	if(access(ifilename, F_OK)==-1) {
		perror("Error: file does not exist!");
		fprintf(stderr, "Error: accessing file: %s: %d\n", ifilename, F_OK);
		//pthread_exit(&ret);
		goto quit;
	}

	//open input file
	fd = open(ifilename, O_RDONLY, 0);
	if(fd==-1) {
		perror("Error: opening input file");
		goto quit;
	}

	//extract base of input filename and create output file name
	//by appending threadnum
	bname = basename(filename);
	ofilename = malloc(strlen(bname)+5);
        memset(ofilename, 0, sizeof(strlen(bname)+5));
	snprintf(ofilename, strlen(bname)+5, "%s.%d", ifilename, tInfo->tnum);

	//create output file
	if((ofd=creat(ofilename, S_IRUSR | S_IWUSR))==-1) {
		perror("Error: Opening output file");
		goto closeifile;
	}

	//get page size aligned offset
	pageSize = sysconf(_SC_PAGESIZE);
	pageMask = ~(pageSize-1);

	if(debug && correctness)
		tInfo->offset?tInfo->offset--:0;

	pAlignedOff = tInfo->offset & pageMask;

	//correct length according to offset alignment
	if(debug && correctness)
		length = pageSize + tInfo->offset - pAlignedOff;
	else
		length = chunkSize + tInfo->offset - pAlignedOff;

	//mmap chunkSize bytes from input file starting from pAlignedOff
	addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, pAlignedOff);
	if(addr==MAP_FAILED) {
		perror("Error: mmap");
		goto closeofile;
	}

	if(debug) {
		printf("THREAD# %d: offset: 0x%jx, pagesize: 0x%lx, chunkSize: 0x%jx, pAlignedOff: 0x%jx, length: 0x%lx, addr: 0x%lx\n",
			tInfo->tnum, tInfo->offset, pageSize, chunkSize, pAlignedOff, length, (unsigned long)addr);
	}

	if(debug & correctness) {
		//write mmapped regionn to STDOUT
		w = write(STDOUT_FILENO, addr, length);
		if(w != length) {
			if(w==-1)
				perror("Error: writing");
			else
				fprintf(stderr, "Error: writing! Only %zd bytes written\n", w);
		}
	}
	else {
		//write mmapped regionn to output file 
		w = write(ofd, addr, length);
		if(w != length) {
			if(w==-1)
				perror("Error: writing");
			else
				fprintf(stderr, "Error: writing! Only 0x%zx bytes written\n", w);
		}
	}

	//unmap
	if(munmap(addr, length)==-1)
		perror("Error: writing"); 

closeofile:
	if(close(ofd)==-1)
		perror("Error: closing output file");
closeifile: 
	free(ofilename);
	if(close(fd)==-1)
		perror("Error: closing input file");
quit:
	pthread_exit(&ret);
}

int main(int argc, char* argv[]) {
	//char* filename = NULL;
	void* ret[NTHREADS];
	int i;
	int nthreads;
	off_t fileSize;  
	struct stat sb;
	struct threadInfo tInfo[NTHREADS]; 

	printf("\n\n%s: spawns - %d - threads, with each thread mmap-ing a chunk of the file proportional to the number of threads\n"
	       "and writes those chunks to unique files in current dir\n\n", argv[0], NTHREADS);
	//check usage
	if(argc < 2) {
		fprintf(stderr, "USAGE! %s <filename> [<debug flag>=0|1]\n", argv[0]);
		return 0;
	}

	if(argc == 3) {
		if(argv[2][0]-'0')
			debug=1;
	}

	filename = (char* )malloc(strlen(argv[1])+3);
	strncpy(filename, argv[1], strlen(argv[1])+3);

	//check for valid input file
	if(access(filename, F_OK)==-1) {
		perror("Error: file does not exist!");
		fprintf(stderr, "Error: accessing file: %s, %s: %d\n", argv[1], filename, F_OK);
		return 1;
	}

	//get input file stats
	if(stat(filename, &sb)==-1) {
		perror("Error: getting file status");
		return 1;
	}
	//get file size
	fileSize = sb.st_size;

	if (debug && correctness)
		nthreads = 2;
	else
		nthreads = NTHREADS;
        //determine chunk size
	chunkSize = fileSize/nthreads;

	memset(tInfo, 0, sizeof(tInfo));
	memset(ret, 0, sizeof(ret));

	//spawn #nthreads
	for(i=0; i<nthreads; ++i) {
		tInfo[i].offset = chunkSize*i;
		tInfo[i].tnum = i+1;
		if(pthread_create(&tInfo[i].thread, NULL, readFileChunk, &tInfo[i]))
			perror("Error: pthread create");
	}

	//wait for #nthreads
	for(i=0; i<nthreads; ++i) {
		if(pthread_join(tInfo[i].thread, &(ret[i])))
			perror("Error: pthread join");
		if(debug && ret[i]) {
			//Note sure if this is the way to check for a canceled
			//thread 
			if(!strcmp(ret[i], "PTHREAD_CANCELED"))
				fprintf(stderr, "Error: thread cancelled\n");
			if(!strcmp(ret[i], "1"))
				fprintf(stderr, "Error: thread encountered some error\n");
		}
	}

	free(filename);
	return 0;
}
