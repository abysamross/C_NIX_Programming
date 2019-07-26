//#include <stdio.h>
volatile int globalVolatileX;
volatile int globalVolatileY_0 = 0;
volatile globalVolatileZ_512 = 512;

int func(int argIntA) {
	volatile int localVolatileB;
	volatile int localVolatileC_0 = 0;
	volatile int localVolatileD_16 = 16;

	globalVolatileZ_512++;
	localVolatileD_16--;

	/*
	printf ("x: %d, y: %d, z: %d, a: %d, b: %d, c: %d, d: %d\n",
			 globalVolatileX, globalVolatileY_0, globalVolatileZ_512, argIntA, localVolatileB, localVolatileC_0, localVolatileD_16);
     */

	return globalVolatileX + globalVolatileY_0 + globalVolatileZ_512 + argIntA + localVolatileB + localVolatileC_0 + localVolatileD_16;
}

int main() {
	int a = -1;
	return func(a);
}
