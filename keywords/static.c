//#include <stdio.h>
static int globalStaticX;
static int globalStaticY_0 = 0;
static int globalStaticZ_256 = 256;

int func(int argIntA) {
	static  int localStaticB;
	static  int localStaticC_0 = 0;
	static  int localStaticD_32 = 32;

	globalStaticZ_256 -= 1;
	localStaticD_32  -= 1;
	/*
    printf("x: %d, y: %d, z: %d, a: %d, b: %d, c: %d, d: %d\n",
			globalStaticX, globalStaticY_0, globalStaticZ_256, argIntA, localStaticB, localStaticC_0, localStaticD_32);
     */

	return globalStaticX + globalStaticY_0 + globalStaticZ_256 + argIntA + localStaticB + localStaticC_0 + localStaticD_32;
}

int main() {
	int a = -1;
	return func(a);
}
