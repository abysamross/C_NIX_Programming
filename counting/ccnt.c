#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {

	FILE* stream = NULL;
	int cc=0;
	char ch;

	if (argc == 2) {

		if (access(argv[1], R_OK) == -1) {
			perror("");
			fprintf(stderr, "%s: Error: Stream \"%s\" does not exist or insufficient permissions\n", argv[0], argv[1]);
			return 1;
		}

		if (!(stream = fopen(argv[1], "r"))) {
			perror("");
			fprintf(stderr, "%s: Error: failed to open stream: %s \n", argv[0], argv[1]);
			return 1;
		}
	}

	if (!stream)
		stream = stdin;

	while ((ch = getc(stream)) != EOF)
		cc++;

	printf("\n%d\n", cc);
	return 0;
}
