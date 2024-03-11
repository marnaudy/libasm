#include "test.h"

#define STR_SIZE 100

void test_strcmp() {
    puts("----- Testing strcmp");
    int test_nbr = 1;
    char *s1, *s2;

    //Basic test
    s1 = "Hello";
    s2 = "World";
    test_int(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_int(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Equal strings
    s1 = "Hello world";
    s2 = "Hello world";
    test_int(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_int(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //One empty string
    s1 = "Hello world";
    s2 = "";
    test_int(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_int(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Two empty strings
    s1 = "";
    s2 = "";
    test_int(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_int(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));
}
