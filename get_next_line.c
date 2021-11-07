#include "get_next_line.h"
char *ft_strdup(char *s1)
{
	size_t src_len;
	char *src;
	char *cpy;
	size_t i;

	src = (char *)s1;
	src_len = ft_strlen(src);
	cpy = malloc(sizeof(char) * (src_len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	size_t s1_size;
	size_t s2_size;
	char *str;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
void	join_bufto_str(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = tmp;
	return ;
}
char	*gnl(ssize_t readr, char **str_input)
{
	int		len;
	char	*tmp;
	char	*str_return;

	if (readr == 0 && **str_input == '\0')
	{
		ft_strdel(str_input);
		return (NULL);
	}
	len = 0;
	while ((*str_input)[len] != '\n' && (*str_input)[len] != '\0')
		len++;
	if ((*str_input)[len] == '\n')
	{
		str_return = ft_substr(*str_input, 0, len + 1);
		tmp = ft_strdup(&(*str_input)[len + 1]);
		ft_strdel(str_input);
		*str_input = tmp;
		return (str_return);
	}
	str_return = ft_substr(*str_input, 0, len);
	ft_strdel(str_input);
	return (str_return);
}
char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readr;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	readr = 1;
	while (readr)
	{
		readr = read(fd, buf, BUFFER_SIZE);
		if (readr == -1)
			return (NULL);
		buf[readr] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else if (str != NULL)
			join_bufto_str(&str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	return (gnl(readr, &str));
}