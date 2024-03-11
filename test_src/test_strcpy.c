#include "test.h"

#define STR_SIZE 100

void test_strcpy() {
    puts("----- Testing strcpy");
    char *src, *dest, *dest2, *ret;
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
    test_str(1, dest, src);
    test_ptr(2, ret, dest);

    //Test overwrite with smaller string
    src[5] = 0;
    ret = ft_strcpy(dest, src);
    test_str(3, dest, src);
    test_ptr(4, ret, dest);

    //Test empty string
    strcpy(src, "");
    ret = ft_strcpy(dest, src);
    test_str(5, dest, src);
    test_ptr(6, ret, dest);

    //Test long string at edge of malloc
    for (int i = 0; i < STR_SIZE; i++) {
        src[i] = STR_SIZE - i - 1;
    }
    ret = ft_strcpy(dest, src);
    test_str(7, dest, src);
    test_ptr(8, ret, dest);

    //Test with overlap
    strcpy(dest, "Hello world");
    strcpy(dest2, "Hello world");
    strcpy(dest2, dest2 + 1);
    ret = ft_strcpy(dest, dest + 1);
    test_str(9, dest, dest2);
    test_ptr(10, ret, dest);

    //Test with dest = src
    strcpy(dest, "Hello world");
    strcpy(dest2, "Hello world");
    strcpy(dest2, dest2);
    ret = ft_strcpy(dest, dest);
    test_str(11, dest, dest2);
    test_ptr(12, ret, dest);

    //Test with a single character
    char c_src, c_dest;
    c_src = 0;
    ret = ft_strcpy(&c_dest, &c_src);
    test_str(13, &c_dest, &c_src);
    test_ptr(14, ret, &c_dest);

    free(src);
    free(dest);
    free(dest2);
}
