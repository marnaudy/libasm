#include "test.h"

void test_int(int test_nbr, int res, int expected) {
    if (res == expected) {
        printf("Test %d passed\n", test_nbr);
    } else {
        printf("Test %d failed. Res = %d expected %d\n", test_nbr, res, expected);
    }
}
