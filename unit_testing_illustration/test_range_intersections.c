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

static char* test_normal_3() {

	int range1[2] = {47, 78};
	int range2[2] = {52, 69};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (52,69)", a1 == 52 && a2 == 69);
	return 0;
}

static char* test_normal_4() {

	int range1[2] = {67, 107};
	int range2[2] = {28, 154};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (67,107)", a1 == 67 && a2 == 107);
	return 0;
}

static char* test_normal_large_1() {

	int range1[2] = {996741532, 1997735688};
	int range2[2] = {996741533, 1997735687};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (996741533,1997735687)", a1 == 996741533 && a2 == 1997735687);
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

	int range1[2] = {31, 49};
	int range2[2] = {12, 31};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (31,31)", a1 == 31 && a2 == 31);
	return 0;
}


static char* test_border_4() {

	int range1[2] = {5, 5};
	int range2[2] = {1, 10};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (5,5)", a1 == 5 && a2 == 5);
	return 0;
}

static char* test_border_5() {

	int range1[2] = {34, 190};
	int range2[2] = {143, 143};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (143,143)", a1 == 143 && a2 == 143);
	return 0;
}

static char* test_border_6() {

	int range1[2] = {899, 899};
	int range2[2] = {899, 899};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (899,899)", a1 == 899 && a2 == 899);
	return 0;
}

static char* test_negative_1() {

	int range1[2] = {4, 7};
	int range2[2] = {10, 20};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (0,0)", a1 == 0 && a2 == 0);
	return 0;
}

static char* test_negative_2() {

	int range1[2] = {23, 24};
	int range2[2] = {21, 22};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (0,0)", a1 == 0 && a2 == 0);
	return 0;
}

static char* test_negative_large_1() {

	int range1[2] = {123923765, 123946715};
	int range2[2] = {123912654, 123923764};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (0,0)", a1 == 0 && a2 == 0);
	return 0;
}

static char* test_invalid_1() {

	int range1[2] = {35, 24};
	int range2[2] = {28, 32};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (-1,-1)", a1 == -1 && a2 == -1);
	return 0;
}

static char* test_invalid_2() {

	int range1[2] = {44, 87};
	int range2[2] = {42, 10};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (-1,-1)", a1 == -1 && a2 == -1);
	return 0;
}


static char* test_invalid_3() {

	int range1[2] = {3, 2};
	int range2[2] = {2, 1};
	int a1 = -1;
	int a2 = -1;
	int* ans[2] = {&a1, &a2};
	
	getIntersection(range1, range2, ans);
	mu_assert_name("Expected: (-1,-1)", a1 == -1 && a2 == -1);
	return 0;
}

void run_all_tests() {

	mu_run_test(test_normal_1);
	mu_run_test(test_normal_2);
	mu_run_test(test_normal_3);
	mu_run_test(test_normal_4);

	mu_run_test(test_normal_large_1);

	mu_run_test(test_border_1);
	mu_run_test(test_border_2);
	mu_run_test(test_border_3);
	mu_run_test(test_border_4);
	mu_run_test(test_border_5);
	mu_run_test(test_border_6);

	mu_run_test(test_negative_1);
	mu_run_test(test_negative_2);

    mu_run_test(test_negative_large_1);

	mu_run_test(test_invalid_1);
	mu_run_test(test_invalid_2);
	mu_run_test(test_invalid_3);
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
