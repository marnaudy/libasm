#include "test.h"
#include <string.h>

void test_strlen() {
    puts("----- Testing strlen");
    test_int(1, ft_strlen(""), strlen(""));
    test_int(2, ft_strlen("Hello"), strlen("Hello"));
    test_int(3, ft_strlen("0"), strlen("0"));
    char s[2];
    s[0] = 1;
    s[1] = 0;
    test_int(4, ft_strlen(s), strlen(s));
    test_int(5, ft_strlen(NULL), 0);
    test_int(6, errno, EFAULT);
}
