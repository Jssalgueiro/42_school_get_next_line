
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h> //define the flags to open function
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
size_t    ft_strlen(const char *str);
char    *ft_strchr(const char *str, int character);
void    *ft_memcpy(void *dest, const void *src, size_t len);
char    *ft_substr(char const *str, unsigned int start, size_t len);
char    *ft_strjoin(char const *str1, char const *str2);
#endif