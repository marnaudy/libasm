#include "test.h"

void    test_list_size() {
    puts("------------------------- Testing list_size");
    int test_nbr = 1;
    t_list *list_begin = NULL;
    char *str = "Hello";

    //Testing with empty list
    test_int(&test_nbr, ft_list_size(list_begin), 0);

    //Testing size 1
    list_push_front(&list_begin, str);
    test_int(&test_nbr, ft_list_size(list_begin), 1);
    free(list_begin);

    //Testing size 10
    list_begin = create_list();
    test_int(&test_nbr, ft_list_size(list_begin), 10);
    free_list(list_begin);
}
