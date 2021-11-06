#include "../includes/so_long.h"

static void	ft_img_init_enemy(t_data *img)
{
	img->enemy_img_1 = mlx_xpm_file_to_image
		(img->mlx, ENEMY_IMG_1, &img->img_width, &img->img_height);
	if (!img->enemy_img_1)
		exit (EXIT_FAILURE);
	img->enemy_img_2 = mlx_xpm_file_to_image
		(img->mlx, ENEMY_IMG_2, &img->img_width, &img->img_height);
	if (!img->enemy_img_2)
		exit (EXIT_FAILURE);
	img->angel_img = mlx_xpm_file_to_image
		(img->mlx, ANGEL_IMG, &img->img_width, &img->img_height);
	if (!img->angel_img)
		exit (EXIT_FAILURE);
	img->weapon_img = mlx_xpm_file_to_image
		(img->mlx, WEAPON_IMG, &img->img_width, &img->img_height);
	if (!img->weapon_img)
		exit (EXIT_FAILURE);
}

static void	ft_img_init_player(t_data *img)
{
	img->player_img = mlx_xpm_file_to_image
		(img->mlx, PLAYER_IMG, &img->img_width, &img->img_height);
	if (!img->player_img)
		exit (EXIT_FAILURE);
	img->player_img_d = mlx_xpm_file_to_image
		(img->mlx, PLAYER_IMG_D, &img->img_width, &img->img_height);
	if (!img->player_img_d)
		exit (EXIT_FAILURE);
	img->player_img_a = mlx_xpm_file_to_image
		(img->mlx, PLAYER_IMG_A, &img->img_width, &img->img_height);
	if (!img->player_img_a)
		exit (EXIT_FAILURE);
}

void	ft_img_init(t_data *img)
{
	img->wall_img = mlx_xpm_file_to_image
		(img->mlx, WALL_IMG, &img->img_width, &img->img_height);
	if (!img->wall_img)
		exit (EXIT_FAILURE);
	img->empty_img = mlx_xpm_file_to_image
		(img->mlx, EMPTY_IMG, &img->img_width, &img->img_height);
	if (!img->empty_img)
		exit (EXIT_FAILURE);
	img->food_img = mlx_xpm_file_to_image
		(img->mlx, COLLECT_IMG, &img->img_width, &img->img_height);
	if (!img->food_img)
		exit (EXIT_FAILURE);
	img->exit_img = mlx_xpm_file_to_image
		(img->mlx, EXIT_IMG, &img->img_width, &img->img_height);
	if (!img->exit_img)
		exit (EXIT_FAILURE);
	ft_img_init_player(img);
	ft_img_init_enemy(img);
}
