#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%i\n", ft_strlen("Hello world"));
    char *str = malloc(100);
    if (str == NULL) {
        return (1);
    }
    ft_strcpy(str, "Hello world!!");
    printf("%s\n", str);
    free(str);
}
