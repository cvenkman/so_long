#include "../includes/so_long.h"

/*
here we change the position on the map,
food count
and check if there are walls or an enemy in front
*/

void	ft_game_W(t_data *img)
{
	if (ft_strchr("1EA", img->map[img->player.row - 1][img->player.col]) == 0)
	{
		img->is_not_wall_exit = true;
		if (img->map[img->player.row - 1][img->player.col] == 'C')
		{
			img->player.food++;
			img->map[img->player.row][img->player.col] = 'F';
		}
		if (img->map[img->player.row][img->player.col] != 'A')
			img->map[img->player.row][img->player.col] = '0';
		img->player.row--;
	}
	else if (img->map[img->player.row - 1][img->player.col] == 'E')
		if (img->player.food == img->food_num)
			close_exit();
}

void	ft_game_A(t_data *img)
{
	if (ft_strchr("1EA", img->map[img->player.row][img->player.col - 1]) == 0)
	{
		img->is_not_wall_exit = true;
		if (img->map[img->player.row][img->player.col - 1] == 'C')
		{
			img->player.food++;
			img->map[img->player.row][img->player.col] = 'F';
		}
		if (img->map[img->player.row][img->player.col] != 'A')
			img->map[img->player.row][img->player.col] = '0';
		img->player.col--;
	}
	else if (img->map[img->player.row][img->player.col - 1] == 'E')
		if (img->player.food == img->food_num)
			close_exit();
}

void	ft_game_S(t_data *img)
{
	if (ft_strchr("1EA", img->map[img->player.row + 1][img->player.col]) == 0)
	{
		img->is_not_wall_exit = true;
		if (img->map[img->player.row + 1][img->player.col] == 'C')
		{
			img->player.food++;
			img->map[img->player.row][img->player.col] = 'F';
		}
		if (img->map[img->player.row][img->player.col] != 'A')
			img->map[img->player.row][img->player.col] = '0';
		img->player.row++;
	}
	else if (img->map[img->player.row + 1][img->player.col] == 'E')
		if (img->player.food == img->food_num)
			close_exit();
}

void	ft_game_D(t_data *img)
{
	if (ft_strchr("1EA", img->map[img->player.row][img->player.col + 1]) == 0)
	{
		img->is_not_wall_exit = true;
		if (img->map[img->player.row][img->player.col + 1] == 'C')
		{
			img->player.food++;
			img->map[img->player.row][img->player.col] = 'F';
		}
		if (img->map[img->player.row][img->player.col] != 'A')
			img->map[img->player.row][img->player.col] = '0';
		img->player.col++;
	}
	else if (img->map[img->player.row][img->player.col + 1] == 'E')
		if (img->player.food == img->food_num)
			close_exit();
}

void	ft_game(t_data *img)
{
	if (img->move.W == true)
		ft_game_W(img);
	else if (img->move.A == true)
		ft_game_A(img);
	else if (img->move.S == true)
		ft_game_S(img);
	else if (img->move.D == true)
		ft_game_D(img);
	ft_move(img);
}
