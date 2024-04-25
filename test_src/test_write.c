#include "test.h"

void test_write() {
    puts("----- Testing write");
    int read_fd = open(".gitignore", O_RDONLY);
    if (read_fd < 0) {
        puts("Open .gitignore for read failed");
        return;
    }
    int write_fd = open("write_test", O_WRONLY | O_CREAT, 644);
    if (read_fd < 0) {
        puts("Opening write_test for writing failed");
        close(read_fd);
        return;
    }
    int test_nbr = 1;
    char buffer[BUFFER_SIZE];

    //Incorrect arguments
    //Negative fd
    test_int(&test_nbr, ft_write(-1, buffer, BUFFER_SIZE), -1);
    test_int(&test_nbr, errno, EBADF);

    //Incorrect positive fd
    test_int(&test_nbr, ft_write(20, buffer, BUFFER_SIZE), -1);
    test_int(&test_nbr, errno, EBADF);

    //File opened as read only
    test_int(&test_nbr, ft_write(read_fd, buffer, BUFFER_SIZE), -1);
    test_int(&test_nbr, errno, EBADF);

    //Null buffer
    test_int(&test_nbr, ft_write(write_fd, NULL, BUFFER_SIZE), -1);
    test_int(&test_nbr, errno, EFAULT);

    //Correct arguments
    //Write count 0
    test_int(&test_nbr, ft_write(write_fd, buffer, 0), 0);

    //Cleanup
    close(read_fd);
    close(write_fd);
    unlink("write_test");
}
