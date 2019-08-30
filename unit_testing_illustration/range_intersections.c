/*
 * Program to find intersection of 2 ranges.
 * (a, b) :  range 1
 * (x, y) :  range 2
 */

enum rangeIndex {st = 0, en};

void getIntersection(int range1[2], int range2[2], int* intersection[2]) {

	*intersection[st] = range2[st] > range1[st] ? (range2[st] > range1[en] ? 0 : range2[st]) :
													(range1[st] > range2[en] ? 0 : range1[st]);

	*intersection[en] = range2[en] < range1[en] ? (range2[en] < range1[st] ? 0 : range2[en]) :
													(range1[en] < range2[st] ? 0 : range1[en]); 
}
