#include "includes/so_long.h"

static int	ft_key(int keycode, t_data *img)
{
	img->is_not_wall_exit = false;
	img->move.W = false;
	img->move.A = false;
	img->move.S = false;
	img->move.D = false;
	if (keycode == ESC)
		close_exit();
	if (keycode == KEY_W)
		img->move.W = true;
	if (keycode == KEY_A)
		img->move.A = true;
	if (keycode == KEY_S)
		img->move.S = true;
	if (keycode == KEY_D)
		img->move.D = true;
	ft_game(img);
	return (1);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_data			img;

	if (argc != 2)
	{
		ft_putstr_fd("no map\n", 0);
		exit(EXIT_FAILURE);
	}
	ft_bzero(&img, sizeof(t_data));
	img.is_weapon = false;
	fd = open(argv[1], O_RDONLY);
	if (map_str_count(fd, &img, argv[1]) == -1)
		exit (EXIT_FAILURE);
	img.mlx = mlx_init();
	img.win = mlx_new_window
		(img.mlx, img.symbols_num * 65, (img.str_num * 65 + 40), "so_long");
	img.pixel = img.symbols_num * 65;
	ft_img_init(&img);
	ft_map_draw(&img, 1);
	mlx_hook(img.win, 2, 0, ft_key, &img);
	mlx_hook(img.win, 17, 0, close_exit, &img);
	mlx_loop(img.mlx);
	sleep(1000);
	exit (EXIT_SUCCESS);
}
