#include "test.h"

#define STR_SIZE 100

void test_strcpy() {
    puts("----- Testing strcpy");
    char *src, *dest, *dest2, *ret;
    int test_nbr = 1;
    src = malloc(STR_SIZE);
    dest = malloc(STR_SIZE);
    dest2 = malloc(STR_SIZE);
    if (!src || !dest || !dest2) {
        puts("ERROR malloc in test");
        return;
    }
    //Basic test
    strcpy(src, "Hello world");
    ret = ft_strcpy(dest, src);
    test_str(&test_nbr, dest, src);
    test_ptr(&test_nbr, ret, dest);

    //Test overwrite with smaller string
    src[5] = 0;
    ret = ft_strcpy(dest, src);
    test_str(&test_nbr, dest, src);
    test_ptr(&test_nbr, ret, dest);

    //Test empty string
    strcpy(src, "");
    ret = ft_strcpy(dest, src);
    test_str(&test_nbr, dest, src);
    test_ptr(&test_nbr, ret, dest);

    //Test long string at edge of malloc
    for (int i = 0; i < STR_SIZE; i++) {
        src[i] = STR_SIZE - i - 1;
    }
    ret = ft_strcpy(dest, src);
    test_str(&test_nbr, dest, src);
    test_ptr(&test_nbr, ret, dest);

    //Test with overlap
    strcpy(dest, "Hello world");
    strcpy(dest2, "Hello world");
    strcpy(dest2, dest2 + 1);
    ret = ft_strcpy(dest, dest + 1);
    test_str(&test_nbr, dest, dest2);
    test_ptr(&test_nbr, ret, dest);

    //Test with dest = src
    strcpy(dest, "Hello world");
    strcpy(dest2, "Hello world");
    strcpy(dest2, dest2);
    ret = ft_strcpy(dest, dest);
    test_str(&test_nbr, dest, dest2);
    test_ptr(&test_nbr, ret, dest);

    //Test with a single character
    char c_src, c_dest;
    c_src = 0;
    ret = ft_strcpy(&c_dest, &c_src);
    test_str(&test_nbr, &c_dest, &c_src);
    test_ptr(&test_nbr, ret, &c_dest);

    free(src);
    free(dest);
    free(dest2);
}
