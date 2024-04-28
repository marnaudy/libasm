#include "test.h"

void test_int(int *test_nbr, int res, int expected) {
    if (res == expected) {
        printf("Test %d passed\n", *test_nbr);
    } else {
        printf("Test %d failed. Res = %d expected %d\n", *test_nbr, res, expected);
    }
    (*test_nbr)++;
}

void test_char(int *test_nbr, char res, char expected) {
    if (res == expected) {
        printf("Test %d passed\n", *test_nbr);
    } else {
        printf("Test %d failed. Res = %d expected %d\n", *test_nbr, res, expected);
    }
    (*test_nbr)++;
}

void test_str(int *test_nbr, char *res, char *expected) {
    if (strcmp(res, expected) == 0) {
        printf("Test %d passed\n", *test_nbr);
    } else {
        printf("Test %d failed. Res = %s expected %s\n", *test_nbr, res, expected);
    }
    (*test_nbr)++;
}

void test_ptr(int *test_nbr, void *res, void *expected) {
    if (res == expected) {
        printf("Test %d passed\n", *test_nbr);
    } else {
        printf("Test %d failed. Res = %p expected %p\n", *test_nbr, res, expected);
    }
    (*test_nbr)++;
}

void test_bool(int *test_nbr, bool res, bool expected) {
    if (res == expected) {
        printf("Test %d passed\n", *test_nbr);
    } else {
        printf("Test %d failed. Res = %s expected %s\n",
            *test_nbr, res ? "true" : "false",
            expected ? "true" : "false");
    }
    (*test_nbr)++;
}

void set_low_memory_limits() {
    struct rlimit limit;
    if (getrlimit(RLIMIT_AS, &limit) < 0) {
        puts("Getrlimit AS call failed");
        return;
    }
    limit.rlim_cur = 10;
    if (setrlimit(RLIMIT_AS, &limit) < 0) {
        puts("Setrlimit AS to low call failed");
        return;
    }
    // if (getrlimit(RLIMIT_DATA, &limit) < 0) {
    //     puts("Getrlimit DATA call failed");
    //     return;
    // }
    // limit.rlim_cur = 10;
    // if (setrlimit(RLIMIT_DATA, &limit) < 0) {
    //     puts("Setrlimit DATA to low call failed");
    //     return;
    // }
}

void set_normal_memory_limits() {
    struct rlimit limit;
    if (getrlimit(RLIMIT_AS, &limit) < 0) {
        puts("Getrlimit AS call failed");
        return;
    }
    limit.rlim_cur = 10000000;
    if (setrlimit(RLIMIT_AS, &limit) < 0) {
        puts("Setrlimit AS to normal call failed");
        return;
    }
    // if (getrlimit(RLIMIT_DATA, &limit) < 0) {
    //     puts("Getrlimit DATA call failed");
    //     return;
    // }
    // limit.rlim_cur = 10000000;
    // if (setrlimit(RLIMIT_DATA, &limit) < 0) {
    //     puts("Setrlimit DATA to normal call failed");
    //     return;
    // }
}

char *make_long_str() {
    char *str = malloc(LONG_STR_SIZE);
    if (!str) {
        puts("Malloc failed to allocate long string");
        return NULL;
    }
    for (int i = 0; i < LONG_STR_SIZE - 1; i++) {
        str[i] = i % 10 + '0';
    }
    str[LONG_STR_SIZE - 1] = 0;
    return str;
}
