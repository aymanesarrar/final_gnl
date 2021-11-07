#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
char *ft_strdel(char **adr_str);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
size_t ft_strlcpy(char *dest, const char *src, size_t dst_size);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(char *s1);
char *ft_strjoin(char const *s1, char const *s2);
void join_bufto_str(char **str, void *buf);
char *gnl(ssize_t readr, char **str_input);
char *get_next_line(int fd);
#endif