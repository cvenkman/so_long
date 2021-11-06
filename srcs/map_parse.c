#include "../includes/so_long.h"

static int	map_make(t_data *img, int fd)
{
	char	*line;
	int		i;
	int		str_number;

	i = 1;
	line = NULL;
	str_number = 0;
	img->map = ft_calloc((img->str_num), (sizeof(char *)));
	if (img->map == NULL)
		ft_print_perror("problem with calloc");
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		img->map[str_number++] = line;
	}
	if (i == -1)
		ft_print_perror("get_next_line problem, bad fd maybe");
	close(fd);
	img->symbols_num = ft_strlen(img->map[0]);
	map_check(img);
	return (0);
}

int	map_str_count(int fd, t_data *img, char *map)
{
	char	*line_tmp;
	int		i;

	i = 1;
	line_tmp = NULL;
	img->str_num = 0;
	while (i == 1)
	{
		i = get_next_line(fd, &line_tmp);
		img->str_num++;
		free(line_tmp);
	}
	if (i == -1)
		ft_print_perror("get_next_line problem, bad fd maybe");
	close(fd);
	fd = open(map, O_RDONLY);
	return (map_make(img, fd));
}
