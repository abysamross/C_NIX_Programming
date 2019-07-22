#include <stdio.h>
#include <unistd.h>
#include "mheader.h"


int checkAccess(char* sname) {

	if (access(sname, R_OK) == -1) {

		perror("Error: ");
		mprint(stderr, "\'%s\', file does not exist or insufficient permissions\n", sname);
		return 1;
	}

	return 0;
}

int openStream(char* sname, FILE** fp) {

	if (!(*fp = fopen(sname, "r"))) {

		perror("Error: ");
		mprint(stderr, "Failed to open file \'%s\',\n", sname);
		return 1;
	}

	return 0;
}

int closeStream(char* sname, FILE* fp) {

	if (fclose(fp) == EOF) {

		perror("Error: ");
		mprint(stderr, "Failed to close file \'%s\'\n", sname);
		return 1;
	}

	return 0;
}
