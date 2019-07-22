#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "mheader.h"

int main(int argc, char* argv[]) {

	int optIndex;
	int lflag = 0;
	int cflag = 0;
	char* larg = NULL;
	char* carg = NULL;
	FILE* fp;

	struct option lOptions[] = {
			{"cc", optional_argument, 0, 'c'},
			{"lc", optional_argument, 0, 'l'},
			{0, 0, 0, 0}
		};

	while (1) {

		int c;

		if ((c = getopt_long(argc, argv, "", lOptions, &optIndex)) == -1)
				break;

		switch (c) {

			case 'c':

				cflag = 1;
				if (optarg) {
					carg = malloc(strlen(optarg)+1);
					strncpy(carg, optarg, strlen(optarg)+1);
				}
				break;

			case 'l':

				lflag = 1;
				if (optarg) {
					larg = malloc(strlen(optarg)+1);
					strncpy(larg, optarg, strlen(optarg)+1);
				}
				break;


			default:

				fprintf(stdout, "Unknown option at: %d\n", optind);

				if (optarg)
					fprintf(stdout, "with arg: %s\n", optarg);
				break;
		}
	}


	if ((!cflag && !lflag) || (optind < argc)) {

		mprint(stderr, "Usage: %s --lc[=stream_name]|--cc[=stream_name]\n", argv[0]);
		goto error;
	}

	if (cflag && carg) {

		if (checkAccess(carg))
			goto error;

		if (openStream(carg, &fp))
			goto error;

		charcount(1, fp);

		if (closeStream(carg, fp))
			goto error;

	} else if (cflag && !carg) {

		if (lflag && !larg)
			charcount(0);
		else
			charcount(1, stdin);
	}

	if (lflag && larg) {

		if (checkAccess(larg))
			goto error;

		if (openStream(larg, &fp))
			goto error;

		linecount(1, fp);

		if (closeStream(larg, fp))
			goto error;

	} else if (lflag && !larg) {

		if (!cflag || carg)
			linecount(0);
	}

	return 0;

error:
	return 1;
}
