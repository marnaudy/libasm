#include "test.h"

void    test_list_push_front(bool skip_mem_check) {
    puts("----- Testing list_push_front");
    int test_nbr = 1;
    t_list *list_begin = NULL;
    char *str = "Test";
    
    //Testing with null list argument
    //This shouldn't crash or do anything
    ft_list_push_front(NULL, NULL);

    //Testing add str to empty list
    ft_list_push_front(&list_begin, str);
    if (list_begin == NULL) {
        puts("list_push_front didn't do anything");
        puts("skipping next tests");
        return;
    }
    test_ptr(&test_nbr, list_begin->data, str);
    test_ptr(&test_nbr, list_begin->next, NULL);

    //Testing add NULL to list
    t_list *save_begin = list_begin;
    ft_list_push_front(&list_begin, NULL);
    test_ptr(&test_nbr, list_begin->data, NULL);
    test_ptr(&test_nbr, list_begin->next, save_begin);
    test_ptr(&test_nbr, list_begin->next->next, NULL);
    test_ptr(&test_nbr, list_begin->next->data, str);
    //Remove first link
    free(list_begin);
    list_begin = save_begin;

    //Test malloc fail
    if (!skip_mem_check) {
        set_low_memory_limits();
        ft_list_push_front(&list_begin, str);
        set_normal_memory_limits();
        //Check that the list hasn't changed and errno is set
        test_ptr(&test_nbr, list_begin, save_begin);
        test_ptr(&test_nbr, list_begin->data, str);
        test_ptr(&test_nbr, list_begin, save_begin);
        test_int(&test_nbr, errno, ENOMEM);
    }
    free(list_begin);
}
