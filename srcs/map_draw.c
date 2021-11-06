#include "../includes/so_long.h"
/*
W - weapon
D - demon
A - dead demon
C - collectible
E - exit
P - player’s starting position
1 - wall
0 - empty space
*/
static void	ft_map_draw_P(t_data *img, int row, int column)
{
	img->player.row = row;
	img->player.col = column;
	mlx_put_image_to_window(img->mlx, img->win, img->player_img,
		column * img->img_width, row * img->img_width);
}

static void	ft_map_draw_DWA(t_data *img, int row, int column)
{
	if (img->map[row][column] == 'D')
	{
		img->for_demon_move += 100;
		if (img->for_demon_move % 500 > 100)
			mlx_put_image_to_window(img->mlx, img->win, img->enemy_img_1,
				column * img->img_width, row * img->img_width);
		else if (img->for_demon_move % 500 < 120)
			mlx_put_image_to_window(img->mlx, img->win, img->enemy_img_2,
				column * img->img_width, row * img->img_width);
	}
	else if (img->map[row][column] == 'W')
		mlx_put_image_to_window(img->mlx, img->win, img->weapon_img,
			column * img->img_width, row * img->img_width);
	else if (img->map[row][column] == 'A')
		mlx_put_image_to_window(img->mlx, img->win, img->angel_img,
			column * img->img_width, row * img->img_width);
}

static void	ft_map_draw_10CE(t_data *img, int row, int column)
{
	if (img->map[row][column] == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->wall_img,
			column * img->img_width, row * img->img_width);
	else if (img->map[row][column] == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->empty_img,
			column * img->img_width, row * img->img_width);
	else if (img->map[row][column] == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->food_img,
			column * img->img_width, row * img->img_width);
	else if (img->map[row][column] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->exit_img,
			column * img->img_width, row * img->img_width);
}

void	ft_map_draw(t_data *img, int flag)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < img->str_num && img->map[row][column] != '\0')
	{
		while (column < img->symbols_num && img->map[row][column] != '\0')
		{
			if (img->map[row][column] == 'P' && flag == 1)
				ft_map_draw_P(img, row, column);
			else if (ft_strchr("10CE", img->map[row][column]) != 0)
				ft_map_draw_10CE(img, row, column);
			else if (ft_strchr("DWA", img->map[row][column]) != 0)
				ft_map_draw_DWA(img, row, column);
			column++;
		}
		column = 0;
		row++;
	}
}
