#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void charcount(int, ...);
void lcount(int, ...);

void mprint(FILE* fp, char* fmt, ...) {
	
	va_list alist;

	va_start(alist, fmt);
	vfprintf(fp, fmt, alist);
	va_end(alist);
}

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
		if (access(sname, R_OK) == -1) {
			perror("Error: ");
			mprint(stderr, "\'%s\', file does not exist or insufficient permissions\n", sname);
			goto error;
		}

		if (!(fp = fopen(sname, "r"))) {
			perror("Error: ");
			mprint(stderr, "\'%s\', failed to open file\n", sname);
			goto error;
		}

		if (cflag)
			charcount(1, fp);

		fseek(fp, 0, SEEK_SET);

		if (lflag)
			lcount(1, fp);

	} else { 

		if (cflag) {
			charcount(0);

			if(lflag)
				freopen("/dev/tty", "r", stdin);
		}

		if (lflag)
			lcount(0);

	}

	return 0;

error:
	return 1;

} 
