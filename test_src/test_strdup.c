#include "test.h"

void test_strdup() {
    puts("----- Testing strdup");
    int test_nbr = 1;
    char *src, *dest;

    //Basic test
    src = "Hello world";
    dest = ft_strdup(src);
    test_str(&test_nbr, dest, src);
    free(dest);
}
