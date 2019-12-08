/*
 * This is the minimal unit testing framework for C found in:
 * http://www.jera.com/techinfo/jtns/jtn002.html
 * (with some stupid additions from my side)
 *
 * and brought to my notice by:
 * Jacob Sorber in https://www.youtube.com/watch?v=vEICc0zygWQ
 *
 */

#ifndef _MINUNIT_H_
#define _MINUNIT_H_

#define mu_assert(message, test)    do {                    \
                                        if (!(test))        \
                                            return "FAILED";\
                                    } while (0)

#define mu_assert_name(message, test)   do {                                            \
                                            if (!(test)) {                              \
                                                printf("\n%s: FAILED! Expected: %s\n",  \
                                                        __func__, message);             \
                                                return "FAILED";                        \
                                            }                                           \
                                        } while (0)

#define mu_run_test_ret(test)   do {                        \
                                    char* message = test(); \
                                    ++tests_run;            \
                                    if (message)            \
                                        return message      \
                                } while (0)

#define mu_run_test(test)   do {                        \
                                char* message = test(); \
                                ++tests_run;            \
                                if (message)            \
                                    ++tests_failed;     \
                            } while (0)

extern int tests_run;
extern int tests_failed;

#endif
