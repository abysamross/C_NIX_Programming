#include <stdio.h>
#include <stdlib.h>
#include "mbst.h"

struct emp {
	int id;
	char* name;
	int age;
};

int main(int argc, char** argv) {

	int N = 12;
	unsigned int seed = 32234323;
	srand(seed);
	bst* bt = initBST();

	for (int i = 0; i < N; ++i) {

		struct emp* a = malloc(sizeof(struct emp));
		a->id = rand();
		//a->id = i;
		a->name = "baker";
		a->age = rand()%60;


		bt->insertT(bt, a->id, a);
	}

	printInorder(bt);
	destroyBST(bt);
	return 0;
}
