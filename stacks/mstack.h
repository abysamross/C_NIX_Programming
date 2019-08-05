#include <stdlib.h>

#ifndef _MSTACK_H_
#define _MSTACK_H_

#ifndef typeof
#define typeof(T) __typeof__(T)
#endif

#define push(S, T, D) ({ 						\
			typeof(T) a   = D;					\
			typeof(T)* ap = malloc(sizeof(T)); 	\
			*ap = a;      						\
			S->push(S, (void*)ap);})

#define pop(S) 		S->pop(S)
#define top(S) 		S->top(S)
#define size(S)		S->size(S) 
#define empty(S)	S->empty(S) 

typedef struct stElem {

	void* val;
	struct stElem* nx;
	struct stElem* pv;

} stElem;

typedef struct stack {

	const char* type;
	void* val;
	stElem* sp;
	stElem* bp;
	int nsize;
	int (*empty) (struct stack*);
	void* (*top) (struct stack*);
	void (*pop) (struct stack*);
	void (*push) (struct stack*, void*);
	int (*size) (struct stack*);

} stack;

stack* initStack();
void freeStack(stack*);

#endif // _MSTACK_H_
