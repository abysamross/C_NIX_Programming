//#include <stdio.h>
//register int globalRegX;
//register int globalRegY_0 = 0;
//register int globalRegZ_256 = 256;

int func(int argIntA) {
	int localRegIntB;
	int localRegIntC_0 = 0;
	int localRegIntD_128 = 128;

	//globalRegZ_256--;
	--localRegIntD_128;

	/*
	printf ("x: %d, y: %d, z: %d, a: %d, b: %d, c: %d, d: %d\n",
			 globalX, globalY_0, globalZ_256, argIntA, localIntB, localIntC_0, localIntD_128);
	 */

	//return globalRegX + globalRegY_0 + globalRegZ_256 + argIntA + localRegIntB + localRegIntC_0 + localRegIntD_128;
	return argIntA + localRegIntB + localRegIntC_0 + localRegIntD_128;

}

int main() {
	int a = -1;
	return func(a);
}
