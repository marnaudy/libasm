#include "test.h"

void    test_create_elem(bool skip_mem_check) {
    puts("----- Testing create_elem");
    int test_nbr = 1;

    //Test basic case with null data
    t_list *new_ptr = ft_create_elem(NULL);
    if (new_ptr == NULL) {
        puts("Create elem returned null");
        return;
    }
    test_ptr(&test_nbr, new_ptr->data, NULL);
    test_ptr(&test_nbr, new_ptr->next, NULL);
    free(new_ptr);

    //Test basic case with data
    char *str = "Hello world";
    new_ptr = ft_create_elem(str);
    if (new_ptr == NULL) {
        puts("Create elem returned null");
        return;
    }
    test_ptr(&test_nbr, new_ptr->data, str);
    test_ptr(&test_nbr, new_ptr->next, NULL);
    free(new_ptr);

    //Test malloc fail
    if (!skip_mem_check) {
        set_low_memory_limits();
        new_ptr = ft_create_elem(str);
        set_normal_memory_limits();
        test_ptr(&test_nbr, new_ptr, NULL);
    }
}
