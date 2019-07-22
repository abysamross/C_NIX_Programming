#include <stdio.h>
#include <stdarg.h>

void mprint(FILE* fp, char* fmt, ...) {
	
	va_list alist;

	va_start(alist, fmt);
	vfprintf(fp, fmt, alist);
	va_end(alist);
}
