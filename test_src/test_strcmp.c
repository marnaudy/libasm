#include "test.h"

void test_strcmp() {
    puts("------------------------- Testing strcmp");
    int test_nbr = 1;
    char *s1, *s2;

    //Basic test
    s1 = "Hello";
    s2 = "World";
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Equal strings
    s1 = "Hello world";
    s2 = "Hello world";
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Equal long strings
    s1 = make_long_str();
    s2 = make_long_str();
    if (!s1 || !s2) {
        return;
    }
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Not equal long strings
    s2[LONG_STR_SIZE - 2] = 'a';
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));
    free(s1);
    free(s2);

    //One empty string
    s1 = "Hello world";
    s2 = "";
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Two empty strings
    s1 = "";
    s2 = "";
    test_sign(&test_nbr, ft_strcmp(s1, s2), strcmp(s1, s2));
    test_sign(&test_nbr, ft_strcmp(s2, s1), strcmp(s2, s1));

    //Test with negative characters
    char s3[2], s4[2];
    s3[0] = -1;
    s4[0] = 'a';
    s3[1] = 0;
    s4[1] = 0;
    test_sign(&test_nbr, ft_strcmp(s3, s4), strcmp(s3, s4));
    test_sign(&test_nbr, ft_strcmp(s4, s3), strcmp(s4, s3));
}
