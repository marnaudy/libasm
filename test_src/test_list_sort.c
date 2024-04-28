#include "test.h"

void    test_list_sort() {
    puts("----- Testing list_sort");
    int test_nbr = 1;
    char *str = "test_str";
    t_list *list = NULL;

    //Test null arguments
    //These shouldn't crash or do anything
    ft_list_sort(NULL, &strcmp);
    ft_list_sort(&list, NULL);

    //Test empty list
    ft_list_sort(&list, &strcmp);
    test_ptr(&test_nbr, list, NULL);

    //Test list size 1
    list_push_front(&list, str);
    t_list *save = list;
    ft_list_sort(&list, &strcmp);
    test_ptr(&test_nbr, list, save);
    test_ptr(&test_nbr, list->data, str);
    test_ptr(&test_nbr, list->next, NULL);
    free(list);
    list = NULL;

    //Test list size 10
    list = create_list();
    ft_list_sort(&list, &strcmp);
    bool is_sorted = list_is_sorted(list, &strcmp);
    test_bool(&test_nbr, is_sorted, true);
    test_int(&test_nbr, list_size(list), 10);
    if (is_sorted) {
        for (int i = 0; i < 10; i++) {
            if (((char *)list->data)[0] != '0' + i) {
                puts("ERROR: List sort modified data");
            }
        }
    }
    free_list(list);
}
