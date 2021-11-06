#include "includes/get_next_line.h"

static int	first_n(char *ost, char **line, char **pointer)
{
	if (ost)
	{
		*pointer = ft_strchr(ost, '\n');
		if (*pointer != 0)
		{
			**pointer = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++(*pointer));
		}
		else
		{
			*line = ft_strdup(ost);
			free(ost);
		}
	}
	else
		*line = ft_strdup("\0");
	if (!(*line))
		return (-1);
	return (0);
}

static int	n_change(char **pointer, char *buff, char **line, char **ost)
{
	char	*temp;

	*pointer = ft_strchr(buff, '\n');
	if (*pointer != 0)
	{
		**pointer = '\0';
		*ost = ft_strdup(++(*pointer));
	}
	temp = *line;
	*line = ft_strjoin(*line, buff);
	free(temp);
	if (!(*line))
		return (-1);
	return (0);
}

static int	gnl(int fd, char **line, char **ost)
{
	char			*buff;
	unsigned int	byte;
	char			*pointer;

	byte = 1;
	pointer = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (first_n(*ost, line, &pointer) == -1)
		return (-1);
	while (pointer == 0 && byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
			return (-1);
		buff[byte] = '\0';
		if (n_change(&pointer, buff, line, ost) == -1)
			return (-1);
	}
	free(buff);
	if (byte != 0)
		return (1);
	*ost = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			a;
	static char	*ost;

	if (!line || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	a = gnl(fd, line, &ost);
	return (a);
}
