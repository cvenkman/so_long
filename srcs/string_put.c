#include "../includes/so_long.h"

void	ft_string_put(t_data *img)
{
	char	*weapon;

	if (img->is_weapon == true)
		weapon = "yes";
	else
		weapon = "no";
	mlx_string_put(img->mlx, img->win, img->pixel / 30,
		(img->str_num * img->img_width + 10), COLOR, "Movement:  ");
	mlx_string_put(img->mlx, img->win, img->pixel / 8,
		(img->str_num * img->img_width + 10), COLOR, ft_itoa(img->move_num));
	mlx_string_put(img->mlx, img->win, (img->pixel / 2 - 120),
		(img->str_num * img->img_width + 10), BLACK, "|  Weapon:  ");
	mlx_string_put(img->mlx, img->win, img->pixel / 2,
		(img->str_num * img->img_width + 10), BLACK, weapon);
	mlx_string_put(img->mlx, img->win, (img->pixel / 2 - 120),
		(img->str_num * img->img_width + 10), COLOR, "|  Weapon:  ");
	mlx_string_put(img->mlx, img->win, img->pixel / 2,
		(img->str_num * img->img_width + 10), COLOR, weapon);
}
