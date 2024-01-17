#ifndef LIBASM_H
#    define LIBASM_H

#include <sys/types.h>

int     ft_strlen(char *str);
char    ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

#endif
