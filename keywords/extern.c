//#include <stdio.h>

extern int globalExternIntE1;
extern int globalExternIntE2;

int func() {
	return globalExternIntE1 + globalExternIntE2;
}
