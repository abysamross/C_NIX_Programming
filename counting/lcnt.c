#include <stdio.h>
#include <unistd.h>
 
int main(int argc, char* argv[]) {

	FILE* stream = stdin;
	char ch;
	int lc = 0;

	if (argc == 2) {

		if (access(argv[1], R_OK) == -1) {
			perror("");
			fprintf(stderr, "%s:  Error: stream \"%s\" does not exist or insufficient permissions\n", argv[0], argv[1]);
			return 1;
		}

		if (!(stream = fopen(argv[1], "r"))) {
			perror("");
			fprintf(stderr, "%s:  Error: failed to open stream \"%s\"\n", argv[0], argv[1]);
			return 1;
		}
	}

	while ((ch = getc(stream)) != EOF)
		if (ch == '\n')
			lc++;

	printf("\n%d\n", lc);
	return 0;
}
