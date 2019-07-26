//#include <stdio.h>
int globalX;
int globalY_0 = 0;
int globalZ_256 = 256;

int func(int argIntA) {
	int localIntB;
	int localIntC_0 = 0;
	int localIntD_128 = 128;

	globalZ_256--;
	--localIntD_128;

	/*
	printf ("x: %d, y: %d, z: %d, a: %d, b: %d, c: %d, d: %d\n",
			 globalX, globalY_0, globalZ_256, argIntA, localIntB, localIntC_0, localIntD_128);
	 */

	return globalX + globalY_0 + globalZ_256 + argIntA + localIntB + localIntC_0 + localIntD_128;

}

int main() {
	int a = -1;
	return func(a);
}
