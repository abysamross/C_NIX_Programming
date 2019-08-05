#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "mstack.h"

static int empty1(stack* st) {

	if (!st->bp || !st->sp)
		return 1;

	return 0;
}

static void* top1(stack* st) {

	if (st->empty1(st))
		return NULL;

	return st->sp->val; 
}

static void pop1(stack* st) {

	if (st->empty1(st))
		return;

	if (st->sp == st->bp)
		st->bp = NULL;

	stElem* tmp = st->sp->pv;
	st->sp->nx = NULL;
	st->sp->pv = NULL;
	free(st->sp->val);
	free(st->sp);
	st->sp = tmp;
	--st->nsize;
}

static void push1(stack* st, void* val) {

	stElem* elm = malloc(sizeof(stElem));
		
	elm->val = val;
	elm->nx = elm->pv = NULL;

	if (!st->bp)
		st->bp = elm;

	if (st->sp) {

		st->sp->nx = elm;
		elm->pv = st->sp;
	}

	st->sp = elm;
	++st->nsize;
}

static int size1(stack* st) {

	return st->nsize;
}

stack* initStack() {

	stack* st = malloc(sizeof(stack)); 
	st->sp = NULL;
	st->bp = NULL;
	st->empty1 = empty1;
	st->top1 = top1;
	st->pop1 = pop1;
	st->push1 = push1;
	st->size1 = size1;
	st->nsize = 0;

	return st;
}

void freeStack(stack* st) {

	while (!st->empty1(st))
		st->pop1(st);

	free(st);
}
