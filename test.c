#include "test.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    // char *str_lit = "Hello world";
    // printf("%i\n", ft_strlen(str_lit));
    // char *str = malloc(100);
    // if (str == NULL) {
    //     return 1;
    // }
    // ft_strcpy(str, "Enter input:\n");
    // ft_write(STDOUT_FILENO, str, ft_strlen(str));
    // int len = ft_read(STDIN_FILENO, str, 99);
    // if (len < 0) {
    //     return 1;
    // }
    // ft_write(STDOUT_FILENO, str, len);
    // free(str);
    test_strlen();
}
