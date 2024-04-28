#ifndef TEST_H
#define TEST_H

#include "libasm_bonus.h"
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
void    test_bool(int *test_nbr, bool res, bool expected);
void    set_low_memory_limits();
void    set_normal_memory_limits();
char    *make_long_str();
void    test_strlen();
void    test_strcpy();
void    test_strcmp();
void    test_strdup(bool skip_mem_check);
void    test_read();
void    test_write();
void    test_atoi_base();
t_list  *create_elem(void *data);
void    list_push_front(t_list **begin_list, void *data);
int     list_size(t_list *begin_list);
bool    list_is_sorted(t_list *begin_list, int (*cmp)());
bool    is_in_list(t_list *begin_list, void *data_ref, int (*cmp)());
t_list  *create_list();
void    free_list(t_list *list_begin);
void    test_create_elem(bool skip_mem_check);
void    test_list_push_front(bool skip_mem_check);
void    test_list_size();
void    test_list_sort();
void    test_list_remove_if();

#endif
