#include "../push_swap.h"

char	*get_new_remainder(char *str)
{
	char	*remainder;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), str = NULL, NULL);
	remainder = ft_strdup(str + i + 1);
	if (!remainder)
		return (free(str), str = NULL, NULL);
	free(str);
	str = NULL;
	return (remainder);
}

char	*get_until_newline(char *remainder)
{
	char	*str;
	int		i;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	read_into_remainder(int fd, char **remainder, char **tmp, int *read_bytes)
{
	while (!ft_strchr(*remainder, '\n') && *read_bytes > 0)
	{
		*read_bytes = read(fd, *tmp, BUFFER_SIZE);
		if (*read_bytes == -1)
			return (free(*tmp), *tmp = NULL, 0);
		(*tmp)[*read_bytes] = '\0';
		*remainder = ft_strjoin(*remainder, *tmp);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*tmp;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (free(remainder), remainder = NULL, NULL);
	line = NULL;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	read_bytes = 1;
	if (!remainder)
		remainder = ft_strdup("");
	if (!read_into_remainder(fd, &remainder, &tmp, &read_bytes))
		return (NULL);
	if (read_bytes != 0 || ft_strlen(remainder) > 0)
	{
		line = get_until_newline(remainder);
		remainder = get_new_remainder(remainder);
	}
	else
		return (free(remainder), remainder = NULL, free(tmp), tmp = NULL, NULL);
	return (free(tmp), tmp = NULL, line);
}
