#ifndef _MYPRINT_H_
#define _MYPRINT_H_

void charcount(int, ...);
void linecount(int, ...);
void mprint(FILE* , char*, ...);
int checkAccess(char*);
int openStream(char*, FILE**);
int closeStream(char*, FILE*);

#endif //_MYPRINT_H_


