#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "divider.h" 

#include "minunit.h"

int tests_run;
int tests_failed;

static char* test_divide_by_zero() {

    divider_s divider; 
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 5, 0);
    mu_assert_name("(0, 0)", ((0 == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_by_one() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 29, 1);
    mu_assert_name("(29, 0)", ((29 == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_zero() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 0, 10);
    mu_assert_name("(29, 0)", ((0 == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_by_self() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 78, 78);
    mu_assert_name("(1, 0)", ((1 == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_perfectly() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 15, 5);
    mu_assert_name("(3, 0)", ((3 == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_larger_by_smaller() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 127, 64);
    mu_assert_name("(1, 63)", ((1 == divider.quotient) && (63 == divider.remainder)));
    return 0;
}

static char* test_divide_smaller_by_larger() {

    divider_s divider;
    memset(&divider, 0, sizeof(divider_s));

    divide(&divider, 9, 18);
    mu_assert_name("(0, 9)", ((0 == divider.quotient) && (9 == divider.remainder)));
    return 0;
}


static char* test_divide_large_numbers_1() {

    divider_s divider;
    unsigned number = 0;
    char string[100] = {'\0'};

    memset(&divider, 0, sizeof(divider_s));
    number = ~number;
    snprintf(string, sizeof(string), "Expected: (0x%x,0x%x)", number, 0);

    divide(&divider, number, 1);
    mu_assert_name(string, ((number == divider.quotient) && (0 == divider.remainder)));
    return 0;
}

static char* test_divide_large_numbers_2() {

    divider_s divider;
    unsigned number = 0;
    char string[100] = {'\0'};

    memset(&divider, 0, sizeof(divider_s));
    number = ~number;
    snprintf(string, sizeof(string), "Expected: (0x%x,0x%x)", 1, 1);

    divide(&divider, number, number - 1);
    mu_assert_name(string, ((1 == divider.quotient) && (1 == divider.remainder)));
    return 0;
}

static char* test_divide_negative_overflow() {

    divider_s divider;
    unsigned number = (1U << sizeof(unsigned));
    unsigned divide_by = ~0U;

    char string[100] = {'\0'};

    memset(&divider, 0, sizeof(divider_s));
    snprintf(string, sizeof(string), "Expected: (0x%x,0x%x)", 1, 1);

    divide(&divider, number, divide_by);
    mu_assert_name(string, ((0 == divider.quotient) && (number == divider.remainder)));
    return 0;
}

static void run_all_tests() {

    mu_run_test(test_divide_by_zero);
    mu_run_test(test_divide_zero);
    mu_run_test(test_divide_by_one);
    mu_run_test(test_divide_by_self);

    mu_run_test(test_divide_perfectly);
    mu_run_test(test_divide_larger_by_smaller);
    mu_run_test(test_divide_smaller_by_larger);

    mu_run_test(test_divide_large_numbers_1);
    mu_run_test(test_divide_large_numbers_2);

    mu_run_test(test_divide_negative_overflow);
}

int main() {

    run_all_tests();

    if (tests_failed) {

        printf("TESTS FAILED\n");

    } else {

        printf("ALL TESTS PASSED\n");
    }

    printf("Tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_run - tests_failed);
    printf("Tests failed: %d\n", tests_failed);
    return 0;
}
