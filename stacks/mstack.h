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
			S->push1(S, (void*)ap);})

#define pop(S) 		S->pop1(S)
#define top(S) 		S->top1(S)
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
	void* (*top1) (struct stack*);
	void (*pop1) (struct stack*);
	void (*push1) (struct stack*, void*);
	int (*size) (struct stack*);

} stack;

stack* initStack();
void freeStack(stack*);

#endif // _MSTACK_H_
