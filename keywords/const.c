//#include <stdio.h>
const int globalConstX;
const int globalConstY_0 = 0;
const int globalConstZ_1000 = 1000;

int func(int argIntA) {
	const int localConstB;
	const int localConstC_0 = 0;
	const int localConstD_64 = 64;

	/*
	printf ("x: %d, y: %d, z: %d, a: %d, b: %d, c: %d, d: %d\n",
			 globalConstX, globalConstY_0, globalConstZ_1000, argIntA, localConstB, localConstC_0, localConstD_64);
	 */

	return globalConstX + globalConstY_0 + globalConstZ_1000 + argIntA + localConstB + localConstC_0 + localConstD_64;
}

int main() {
	int a = -1;
	return func(a);
}
