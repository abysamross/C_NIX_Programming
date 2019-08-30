#include<stdio.h>
#include "range_intersections.h"
#include "minunit.h"

int tests_run = 0;
int tests_failed = 0;

static char* test_normal_1() {

	int range1[2] = {4, 7};
	int range2[2] = {6, 9};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (6,7)", a1 == 6 && a2 == 7);
	return 0;
}

static char* test_normal_2() {

	int range1[2] = {4, 7};
	int range2[2] = {1, 5};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (4,5)", a1 == 4 && a2 == 5);
	return 0;
}

static char* test_border_1() {

	int range1[2] = {4, 7};
	int range2[2] = {4, 7};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (4,7)", a1 == 4 && a2 == 7);
	return 0;
}

static char* test_border_2() {

	int range1[2] = {4, 7};
	int range2[2] = {7, 9};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (7,7)", a1 == 7 && a2 == 7);
	return 0;
}

static char* test_border_3() {

	int range1[2] = {4, 7};
	int range2[2] = {10, 20};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (0,0)", a1 == 0 && a2 == 0);
	return 0;
}

static char* test_border_5() {

	int range1[2] = {23, 24};
	int range2[2] = {21, 22};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (0,0)", a1 == 0 && a2 == 0);
	return 0;
}

/*
static char* run_all_tests_ret() {

	mu_run_test(test_normal_1);
	mu_run_test(test_normal_2);
	mu_run_test(test_border_1);
	mu_run_test(test_border_2);
	mu_run_test(test_border_3);
	mu_run_test(test_border_5);
	return 0;
}
*/

void run_all_tests() {

	mu_run_test(test_normal_1);
	mu_run_test(test_normal_2);
	mu_run_test(test_border_1);
	mu_run_test(test_border_2);
	mu_run_test(test_border_3);
	mu_run_test(test_border_5);
}

int main(int argc, char* argv[]) {

	/*
	char* results = run_all_tests_ret();

	if (results != 0)
		printf("\n%s \n", results);

	else
		printf("\nALL TESTS PASSED\n");
	*/

	run_all_tests();

	if (tests_failed)
		printf("\nTESTS FAILED\n");

	else
		printf("\nALL TESTS PASSED\n");

	printf("Tests Run: %d\n", tests_run);
	printf("Tests Passed: %d\n", tests_run - tests_failed);
	printf("Tests Failed: %d\n", tests_failed);
	return 0;
}
