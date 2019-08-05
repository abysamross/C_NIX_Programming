#include <stdio.h>
#include "mstack.h"

struct test {
	int a;
	float b;
};

void func1(stack* st) {

	int N = 15;
	int i = 0;
	int j = 0;
	struct test sArr[N][N];

	for (i = 0; i < N; ++i) {

		for (j = 0; j < N; ++j) {

			sArr[i][j].a = j;
			sArr[i][j].b = j + (float)j/10.0;
		}

		push(st, struct test(*)[N], &sArr[i]);
	}

	i = 0;
	while (!empty(st)) {

		struct test(*s)[N] = *(struct test(**)[N])top(st);
		pop(st);

		printf("%d: \n", i);
		for (j = 0; j < N; ++j)
			printf("%d: %d, %f\n", j, (*s + j)->a, (*s + j)->b);

		++i;
		printf("\n");
	}

	printf("size: %d\n\n", size(st));
	freeStack(st);
	printf("\n");
}

int main(int argc, char* argv[]) {

	stack* st = initStack();
	int N = 10;
	int i = 0;

	struct test* sArr = malloc(N*sizeof(struct test));

	for (i = 0; i < N; ++i) {

		(sArr+i)->a = i;
		(sArr+i)->b = i + (float)i/10.0;
		push(st, struct test, *(sArr + i));
	}

	free(sArr);

	i = 0;
	while (!empty(st)) {

		struct test t = *(struct test* )top(st);
		printf("%d. %d, %f\n", i, t.a, t.b);
		pop(st);
		++i;
	}

	printf("size: %d\n\n", size(st));

	func1(st);
	return 0;
}
