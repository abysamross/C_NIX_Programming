#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int charcount(int argc, ...) {

	FILE* stream = NULL;
	int cc = 0;
	int lc = 0;
	char ch;


	if (argc) {
		va_list alist;
		va_start(alist, argc);
		stream = (FILE* ) va_arg(alist, char*);
		va_end(alist);
	}

	if (!stream)
		stream = stdin;

	while ((ch = getc(stream)) != EOF) {

		cc++;

		if (argc == 0 && ch == '\n')
			lc++;
	}

	printf("%d\n", cc);

	if (argc == 0)
		printf("%d\n", lc);

	return 0;
}
