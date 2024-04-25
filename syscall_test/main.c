#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file", O_RDONLY);
    char buffer[100];
    read(fd, buffer, 100);
    close(fd);
}
