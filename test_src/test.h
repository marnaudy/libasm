#ifndef TEST_H
#define TEST_H

#include "libasm.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void    test_int(int test_nbr, int res, int expected);
void    test_str(int test_nbr, char *res, char *expected);
void    test_ptr(int test_nbr, void *res, void *expected);
void    test_strlen();
void    test_strcpy();

#endif
