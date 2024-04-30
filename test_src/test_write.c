#include "test.h"

void test_write() {
    puts("------------------------- Testing write");
    int read_fd = open("read_test", O_RDONLY | O_CREAT, 0644);
    if (read_fd < 0) {
        puts("Open read_test for read failed");
        return;
    }
    int write_fd = open("write_test", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (write_fd < 0) {
        puts("Opening write_test for writing failed");
        close(read_fd);
        return;
    }
    char *long_str = make_long_str();
    if (long_str == NULL) {
        close(read_fd);
        close(write_fd);
        return;
    }
    int test_nbr = 1;

    //Incorrect arguments
    //Negative fd
    errno = 0;
    test_int(&test_nbr, ft_write(-1, long_str, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //Incorrect positive fd
    errno = 0;
    test_int(&test_nbr, ft_write(20, long_str, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //File opened as read only
    errno = 0;
    test_int(&test_nbr, ft_write(read_fd, long_str, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //Null buffer
    errno = 0;
    test_int(&test_nbr, ft_write(write_fd, NULL, 1), -1);
    test_int(&test_nbr, errno, EFAULT);

    //Correct arguments
    errno = 0;
    //Write count 0
    test_int(&test_nbr, ft_write(write_fd, long_str, 0), 0);
    test_int(&test_nbr, errno, 0);

    //Write count 1
    test_int(&test_nbr, ft_write(write_fd, long_str, 1), 1);
    test_int(&test_nbr, errno, 0);

    //Write rest of string
    test_int(&test_nbr, ft_write(write_fd, &long_str[1], LONG_STR_SIZE - 2), LONG_STR_SIZE - 2);
    test_int(&test_nbr, errno, 0);

    //Check the write file contains the correct text
    char buffer[LONG_STR_SIZE];
    close(write_fd);
    write_fd = open("write_test", O_RDONLY);
    if (write_fd < 0) {
        puts("Opening write_test for reading failed");
        close(read_fd);
        free(long_str);
        return;
    }
    int ret = read(write_fd, buffer, LONG_STR_SIZE);
    test_int(&test_nbr, ret, LONG_STR_SIZE - 1);
    if (ret < 0) {
        puts("Error reading write_test");
        close(write_fd);
        close(read_fd);
        free(long_str);
        return;
    }
    buffer[ret] = 0;
    test_str(&test_nbr, buffer, long_str);

    //Cleanup
    close(read_fd);
    close(write_fd);
    unlink("write_test");
    unlink("read_test");
    free(long_str);
}
