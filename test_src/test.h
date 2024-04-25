#ifndef TEST_H
#define TEST_H

#include "libasm.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define LONG_STR_SIZE 10000

void    test_int(int *test_nbr, int res, int expected);
void    test_char(int *test_nbr, char res, char expected);
void    test_str(int *test_nbr, char *res, char *expected);
void    test_ptr(int *test_nbr, void *res, void *expected);
void    set_low_memory_limits();
void    set_normal_memory_limits();
char    *make_long_str();
void    test_strlen();
void    test_strcpy();
void    test_strcmp();
void    test_strdup(bool skip_mem_check);
void    test_read();
void    test_write();

#endif
