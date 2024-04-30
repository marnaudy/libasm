#include "test.h"

void test_read() {
    puts("------------------------- Testing read");
    //Create test read file with known content
    int fd = open("read_test", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        puts("Opening read_test for writing failed");
        return;
    }
    char *long_str = make_long_str();
    if (long_str == NULL) {
        close(fd);
        return;
    }
    int ret = write(fd, long_str, LONG_STR_SIZE - 1);
    if (ret != LONG_STR_SIZE - 1) {
        puts("Failed to write long string to read_test");
        close(fd);
        free(long_str);
        return;
    }
    close(fd);

    //Open read and write fds to use for testing
    int read_fd = open("read_test", O_RDONLY);
    if (read_fd < 0) {
        puts("Open read_test for read failed");
        return;
    }
    int write_fd = open("write_test", O_WRONLY | O_CREAT, 0644);
    if (write_fd < 0) {
        puts("Opening write_test for writing failed");
        close(read_fd);
        return;
    }
    int test_nbr = 1;
    char buffer[LONG_STR_SIZE];

    //Incorrect arguments
    //Negative fd
    test_int(&test_nbr, ft_read(-1, buffer, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //Incorrect positive fd
    test_int(&test_nbr, ft_read(20, buffer, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //File opened as write only
    test_int(&test_nbr, ft_read(write_fd, buffer, 1), -1);
    test_int(&test_nbr, errno, EBADF);

    //Null buffer
    test_int(&test_nbr, ft_read(read_fd, NULL, 1), -1);
    test_int(&test_nbr, errno, EFAULT);

    //Correct arguments
    //Read count 0
    errno = 0;
    test_int(&test_nbr, ft_read(read_fd, buffer, 0), 0);
    test_int(&test_nbr, errno, 0);

    //Read count 1
    test_int(&test_nbr, ft_read(read_fd, buffer, 1), 1);
    test_int(&test_nbr, errno, 0);
    test_char(&test_nbr, buffer[0], long_str[0]);

    //Read rest of file
    buffer[LONG_STR_SIZE - 2] = 0;
    test_int(&test_nbr, ft_read(read_fd, buffer, LONG_STR_SIZE), LONG_STR_SIZE - 2);
    test_int(&test_nbr, errno, 0);
    test_str(&test_nbr, buffer, &long_str[1]);

    //Read at end of file
    test_int(&test_nbr, ft_read(read_fd, buffer, LONG_STR_SIZE), 0);
    test_int(&test_nbr, errno, 0);
    test_str(&test_nbr, buffer, &long_str[1]);

    //Cleanup
    close(read_fd);
    close(write_fd);
    unlink("read_test");
    unlink("write_test");
    free(long_str);
}
