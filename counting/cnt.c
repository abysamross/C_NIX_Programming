#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "mheader.h"

int main(int argc, char* argv[]) {

	int opt;
	int cflag = 0;
	int lflag = 0;
	FILE* fp = NULL;
	char* sname = NULL;

	while ((opt = getopt(argc, argv, "-lc")) != -1) {

		switch (opt) {

			case 'c':

				cflag = 1;
				break;

			case 'l':

				lflag = 1;
				break;

			case '?':

				mprint(stderr, "Usage: %s -l|-c [<stream name>]\n", argv[0]);
				goto error;

			default:

				if (sname) {
					mprint(stderr, "Usage: %s -l|-c [<stream name>]\nInvalid argument argv[%d]: %s\n", argv[0], optind-1, optarg);
					goto error;
				}
				else
					sname = optarg;
				break;
		}
	}

	if(!lflag && !cflag && optind <= 2) {

		mprint(stderr, "Usage: %s -l|-c [<stream name>]\n", argv[0]);
		goto error;
	}

	if (sname) {

		if (checkAccess(sname))
			goto error;

		if (openStream(sname, &fp))
			goto error;

		if (cflag)
			charcount(1, fp);

		fseek(fp, 0, SEEK_SET);

		if (lflag)
			linecount(1, fp);

		if (closeStream(sname, fp))
			goto error;

	} else { 

		if (cflag)
			charcount(0);

		else if (lflag)
			linecount(0);
		/*
		 *	if(lflag)
		 *   	freopen("/dev/tty", "r", stdin);
		 *}
		 */
	}

	return 0;

error:
	return 1;

} 
