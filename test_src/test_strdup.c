#include "test.h"

void test_strdup(bool skip_mem_check) {
    puts("------------------------- Testing strdup");
    int test_nbr = 1;
    char *src, *dest;

    //Basic test
    src = "Hello world";
    dest = ft_strdup(src);
    test_str(&test_nbr, dest, src);
    free(dest);

    //Empty test
    src = "";
    dest = ft_strdup(src);
    test_str(&test_nbr, dest, src);
    free(dest);

    //Long test
    char *long_str = make_long_str();
    if (!long_str) {
        return;
    }
    src = long_str;
    dest = ft_strdup(src);
    test_str(&test_nbr, dest, src);
    test_ptr(&test_nbr, src, long_str);
    free(dest);

    if (!skip_mem_check) {
        //Long test with malloc fail
        set_low_memory_limits();
        src = long_str;
        dest = ft_strdup(src);
        set_normal_memory_limits();
        test_ptr(&test_nbr, dest, NULL);
        test_int(&test_nbr, errno, ENOMEM);
        test_ptr(&test_nbr, src, long_str);
        free(dest);
    }
    free(long_str);
}
