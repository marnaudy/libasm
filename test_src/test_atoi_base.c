#include "test.h"

void    test_atoi_base() {
    puts("----- Testing atoi_base");
    int test_nbr = 1;
    char *base10 = "0123456789";
    char *base16 = "0123456789abcdef";
    
    //Invalid base
    puts("Invalid base");
    test_int(&test_nbr, ft_atoi_base("10", ""), 0);
    test_int(&test_nbr, ft_atoi_base("10", "1"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "010"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01+"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01-"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01 "), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01\f"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01\t"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01\n"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01\r"), 0);
    test_int(&test_nbr, ft_atoi_base("10", "01\v"), 0);
    
    //Basic positive formatting
    puts("Basic formatting");
    test_int(&test_nbr, ft_atoi_base("", base10), 0);
    test_int(&test_nbr, ft_atoi_base("0", base10), 0);
    test_int(&test_nbr, ft_atoi_base("1", base10), 1);
    test_int(&test_nbr, ft_atoi_base("1234567890", base10), 1234567890);

    //Formatting with signs
    puts("Formatting with signs");
    test_int(&test_nbr, ft_atoi_base("+", base10), 0);
    test_int(&test_nbr, ft_atoi_base("-", base10), 0);
    test_int(&test_nbr, ft_atoi_base("-0", base10), 0);
    test_int(&test_nbr, ft_atoi_base("+-0", base10), 0);
    test_int(&test_nbr, ft_atoi_base("-1", base10), -1);
    test_int(&test_nbr, ft_atoi_base("++++-1", base10), -1);
    test_int(&test_nbr, ft_atoi_base("-+-+1", base10), 1);
    test_int(&test_nbr, ft_atoi_base("-+-+-+1", base10), -1);
    test_int(&test_nbr, ft_atoi_base("+-+1234567890", base10), -1234567890);
    test_int(&test_nbr, ft_atoi_base("+-+-+1234567890", base10), 1234567890);

    //Formatting with whitespace
    puts("Formatting with whitespace");
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n0", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n1", base10), 1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n1234567890", base10), 1234567890);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-0", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-0", base10), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-1", base10), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n++++-1", base10), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-+-+1", base10), 1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-+-+-+1", base10), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-+1234567890", base10), -1234567890);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-+-+1234567890", base10), 1234567890);

    //Formatting with trailing characters
    puts("Formatting with trailing characters");
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+Z", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n0+aa", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n1+aa", base16), 1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \nffff+aa", base16), 65535);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+Aaa", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-Aaa", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-0Aaa", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-0Aaa", base16), 0);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-1Aaa", base16), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n++++-1 aaa", base16), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-+-+1 aaa", base16), 1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n-+-+-+1 aaa", base16), -1);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-+ffff aaa", base16), -65535);
    test_int(&test_nbr, ft_atoi_base(" \f\t\n\r\v \n+-+-+ffff aaa", base16), 65535);
}
