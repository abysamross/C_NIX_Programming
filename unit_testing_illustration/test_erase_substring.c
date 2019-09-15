#include <stdio.h>
#include "erase_substring.h"
#include "minunit.h"

int tests_run;
int tests_failed;

static char* test_basic_positive(void) {

    char string[]   = "aby sam ross";
    char erase[]    = "sam ";
    char result[]   = "aby ross";

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0;
}

static char* test_basic_negative(void) {

    char string[]   = "aby sam ross";
    char erase[]    = "diana";
    char result[]   = "aby sam ross";

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0;
}

static char* test_multiple_occurences(void) {

    char string[]   = "erase This is erase a random erase text containing erase erase keywords to be erase erased erase erase ";
    char erase[]    = "erase ";
    char result[]   = "This is a random text containing keywords to be erased ";

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0;
}

static char* test_empty_string(void) {

    char string[]   = "";
    char erase[]    = "some text";
    char result[]   = {'\0'};

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0;
}

static char* test_empty_erase(void) {

    char string[]   = "some text";
    char erase[]    = "";
    char result[]   = "some text";

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0; }

static char* test_empty_string_erase(void) {

    char string[]   = "";
    char erase[]    = "";

    erase_substring(string, erase);
    mu_assert_name("\"\"", ((0 == strcmp(string, "")) && (0 == strcmp(erase, ""))));
    return 0;
}

static char* test_same_text(void) {

    char string[]   = "same text";
    char erase[]    = "same text";

    erase_substring(string, erase);
    mu_assert_name("\"\"", (0 == strcmp(string, "")));
    return 0;
}

static char* test_null_string(void) {

    char* string    = NULL;
    char erase[]    = "some text";

    erase_substring(string, erase);
    mu_assert_name("", (NULL == string) && (0 == strcmp(erase, "some text")));
    return 0;
}

static char* test_null_erase(void) {

    char string[]   = "some text";
    char* erase     = NULL;
    char result[]   = "some text";

    erase_substring(string, erase);
    mu_assert_name(result, (NULL == erase) && (0 == strcmp(string, result)));
    return 0;
}

static char* test_space_erase(void) {

    char string[]   = "   reading betw   een the w o r d s  ! ";
    char erase[]    = " ";
    char result[]   = "readingbetweenthewords!";

    erase_substring(string, erase);
    mu_assert_name(result, (0 == strcmp(string, result)));
    return 0;
}

static void run_all_tests(void) {

    mu_run_test(test_basic_positive);
    mu_run_test(test_basic_negative);
    mu_run_test(test_multiple_occurences);
    mu_run_test(test_empty_string);
    mu_run_test(test_empty_erase);
    mu_run_test(test_empty_string_erase);
    mu_run_test(test_same_text);
    mu_run_test(test_null_string);
    mu_run_test(test_null_erase);
    mu_run_test(test_space_erase);
}

int main() {

    run_all_tests();

    if (tests_failed) {

        printf("TESTS FAILED\n");

    } else {

        printf("ALL TESTS PASSED\n");
    }

    printf("Test Run: %d\n", tests_run);
    printf("Test Passed: %d\n", tests_run - tests_failed);
    printf("Test Failed: %d\n", tests_failed);

    return 0;
}
