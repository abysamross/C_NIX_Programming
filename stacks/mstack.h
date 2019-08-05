#include <stdlib.h>

#ifndef _MSTACK_H_
#define _MSTACK_H_

#ifndef typeof
#define typeof(T) __typeof__(T)
#endif

#define push(S, T, D) ({						\
			typeof(stack*) s  = S;				\
			typeof(T) a   = D;					\
			typeof(T)* ap = malloc(sizeof(T));	\
			*ap = a;							\
			s->push1(s, (void*)ap);})

#define pop(S) ({				\
		typeof(stack*) s  = S;	\
		s->pop1(s);})

#define top(S) ({				\
		typeof(stack*) s  = S;	\
		s->top1(s);})

#define size(S) ({				\
		typeof(stack*) s  = S;	\
		s->size1(s);})

#define empty(S) ({				\
		typeof(stack*) s  = S;	\
		s->empty1(s);})

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
	int (*empty1) (struct stack*);
	void* (*top1) (struct stack*);
	void (*pop1) (struct stack*);
	void (*push1) (struct stack*, void*);
	int (*size1) (struct stack*);

} stack;

stack* initStack();
void freeStack(stack*);

#endif // _MSTACK_H_
