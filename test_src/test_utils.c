#include "test.h"

void test_int(int test_nbr, int res, int expected) {
    if (res == expected) {
        printf("Test %d passed\n", test_nbr);
    } else {
        printf("Test %d failed. Res = %d expected %d\n", test_nbr, res, expected);
    }
}

void test_str(int test_nbr, char *res, char *expected) {
    if (strcmp(res, expected) == 0) {
        printf("Test %d passed\n", test_nbr);
    } else {
        printf("Test %d failed. Res = %s expected %s\n", test_nbr, res, expected);
    }
}

void test_ptr(int test_nbr, void *res, void *expected) {
    if (res == expected) {
        printf("Test %d passed\n", test_nbr);
    } else {
        printf("Test %d failed. Res = %p expected %p\n", test_nbr, res, expected);
    }
}
