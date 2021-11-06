#include "../includes/so_long.h"

static void	ft_demon(t_data *img)
{
	if (img->map[img->player.row][img->player.col] == 'W')
	{
		img->is_weapon = true;
		img->map[img->player.row][img->player.col] = '0';
		ft_putstr_fd("now you have a weapon\n", 0);
		mlx_string_put(img->mlx, img->win, (img->pixel / 2 - 120),
			(img->str_num * img->img_width + 10), BLACK, "|  Weapon:  ");
		mlx_string_put(img->mlx, img->win, img->pixel / 2,
			(img->str_num * img->img_width + 10), BLACK, "no");
	}
	if (img->map[img->player.row][img->player.col] == 'D'
		&& img->is_weapon == false)
	{
		ft_putstr_fd("you lose\n", 0);
		exit(EXIT_FAILURE);
	}
	else if (img->map[img->player.row][img->player.col] == 'D'
		&& img->is_weapon == true)
	{
		img->map[img->player.row][img->player.col] = 'A';
		ft_putstr_fd("you killed the demon\n", 0);
		ft_map_draw(img, 0);
	}
}

void	ft_move(t_data *img)
{
	if (img->map[img->player.row][img->player.col] == 'W'
		|| img->map[img->player.row][img->player.col] == 'D')
		ft_demon(img);
	ft_map_draw(img, 0);
	if (img->move.W == true || img->move.S == true)
		mlx_put_image_to_window(img->mlx, img->win, img->player_img,
			img->player.col * img->img_width, img->player.row * img->img_width);
	else if (img->move.A == true)
		mlx_put_image_to_window(img->mlx, img->win, img->player_img_a,
			img->player.col * img->img_width, img->player.row * img->img_width);
	else if (img->move.D == true)
		mlx_put_image_to_window(img->mlx, img->win, img->player_img_d,
			img->player.col * img->img_width, img->player.row * img->img_width);
	if (img->is_not_wall_exit == true)
	{
		mlx_string_put(img->mlx, img->win, (img->pixel / 30),
			(img->str_num * img->img_width + 10), BLACK, "Movement:  ");
		mlx_string_put(img->mlx, img->win, (img->pixel / 8),
			(img->str_num *img->img_width +10), BLACK, ft_itoa(img->move_num));
		img->move_num++;
		ft_string_put(img);
	}
}
