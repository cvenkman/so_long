#include "../includes/so_long.h"

static void	map_check_rectangular(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->str_num)
	{
		if ((int)ft_strlen(img->map[i]) != img->symbols_num)
			ft_print_error("map must be rectangular");
		i++;
	}
}

static void	map_check_struct_symbols(t_sym *symbols_struct)
{
	if (symbols_struct->C == 0)
		ft_print_error("no collectible in map");
	if (symbols_struct->P == 0)
		ft_print_error("no player in map");
	if (symbols_struct->P > 1)
		ft_print_error("must be one player");
	if (symbols_struct->E != 1)
		ft_print_error("no exit in map or more than one exit");
}

static void	map_check_symbols(t_data *img, t_sym *symbols_struct)
{
	int	strings;
	int	symbols;

	strings = 0;
	symbols = 0;
	while (strings < img->str_num && img->map[strings][symbols] != '\0')
	{
		while (symbols < img->symbols_num && img->map[strings][symbols] != '\0')
		{
			if (img->map[strings][symbols] == 'C')
				symbols_struct->C++;
			else if (img->map[strings][symbols] == 'E')
				symbols_struct->E++;
			else if (img->map[strings][symbols] == 'P')
				symbols_struct->P++;
			else if (ft_strchr("01DWA", img->map[strings][symbols]) == 0)
				ft_print_error("map must be composed of only 01CEPDWA");
			symbols++;
		}
		symbols = 0;
		strings++;
	}
	img->food_num = symbols_struct->C;
}

static void	map_check_walls(t_data *img)
{
	int	strings;
	int	symbols;

	strings = 0;
	symbols = 0;
	if (!img->map[0][0])
		ft_print_error("empty map");
	while (symbols < img->symbols_num && img->map[0][symbols] == '1'
		&& img->map[img->str_num - 1][symbols] == '1')
		symbols++;
	while (strings < img->str_num && img->map[strings][0] == '1'
		&& img->map[strings][img->symbols_num - 1] == '1')
		strings++;
	if (symbols != img->symbols_num || strings != img->str_num)
		ft_print_error("map must be rectangular and closed by walls");
}

void	map_check(t_data *img)
{
	t_sym	symbols_struct;

	ft_bzero(&symbols_struct, sizeof(t_sym));
	map_check_walls(img);
	map_check_symbols(img, &symbols_struct);
	map_check_struct_symbols(&symbols_struct);
	map_check_rectangular(img);
}
