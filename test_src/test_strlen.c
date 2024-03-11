#include "test.h"

void test_strlen() {
    puts("----- Testing strlen");
    int test_nbr = 1;
    test_int(&test_nbr, ft_strlen(""), strlen(""));
    test_int(&test_nbr, ft_strlen("Hello"), strlen("Hello"));
    test_int(&test_nbr, ft_strlen("0"), strlen("0"));
    char s[2];
    s[0] = 1;
    s[1] = 0;
    test_int(&test_nbr, ft_strlen(s), strlen(s));
    test_int(&test_nbr, ft_strlen(NULL), 0);
    test_int(&test_nbr, errno, EFAULT);
}
