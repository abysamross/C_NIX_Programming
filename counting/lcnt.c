#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
 
int linecount(int argc, ...) {

	char ch;
	int lc = 0;
	FILE* stream = NULL;
	va_list alist;

	if(argc) {
		va_start(alist, argc);
		stream = (FILE*) va_arg(alist, int*);
		va_end(alist);
	}

	if (!stream)
		stream = stdin;

	while ((ch = getc(stream)) != EOF)
		if (ch == '\n')
			lc++;

	printf("%d\n", lc);
	return 0;
}
