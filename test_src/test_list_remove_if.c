#include "test.h"

int return_zero(void *data1, void *data2) {
    (void) data1;
    (void) data2;
    return 0;
}

void test_list_remove_if() {
    puts("----- Testing list_remove_if");
    int test_nbr = 1;
    t_list *list = NULL;
    char *str = "test_str";

    //Null arguments
    ft_list_remove_if(NULL, NULL, &strcmp, &free);
    ft_list_remove_if(&list, NULL, NULL, &free);
    ft_list_remove_if(&list, NULL, &strcmp, NULL);

    //Empty list
    ft_list_remove_if(&list, NULL, &strcmp, &free);
    test_ptr(&test_nbr, list, NULL);

    //List size one without match
    list_push_front(&list, str);
    t_list *save = list;
    ft_list_remove_if(&list, "a", &strcmp, &free);
    test_ptr(&test_nbr, list, save);
    test_ptr(&test_nbr, list->data, str);
    test_ptr(&test_nbr, list->next, NULL);

    //List size one with match
    list->data = strdup(str);
    ft_list_remove_if(&list, str, &strcmp, &free);
    test_ptr(&test_nbr, list, NULL);

    //List size 10 with no match
    free(list);
    list = create_list();
    save = list;
    ft_list_remove_if(&list, str, &strcmp, &free);
    test_ptr(&test_nbr, list, save);
    test_int(&test_nbr, list_size(list), 10);

    //List size 10 with one match
    ft_list_remove_if(&list, "0", &strcmp, &free);
    test_int(&test_nbr, list_size(list), 9);
    test_bool(&test_nbr, is_in_list(list, "0", &strcmp), false);
    
    //List size 10 with two matches
    list_push_front(&list, strdup("4"));
    ft_list_remove_if(&list, "4", &strcmp, &free);
    test_int(&test_nbr, list_size(list), 8);
    test_bool(&test_nbr, is_in_list(list, "4", &strcmp), false);

    //List size 9 with all matches
    ft_list_remove_if(&list, "0", &return_zero, &free);
    test_ptr(&test_nbr, list, NULL);
}
