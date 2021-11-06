#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h> //exit
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53
# define WALL_IMG "images/wall.xpm"
# define EMPTY_IMG "images/empty.xpm"
# define COLLECT_IMG "images/food.xpm"
# define EXIT_IMG "images/exit.xpm"
# define PLAYER_IMG "images/player.xpm"
# define PLAYER_IMG_D "images/player_d.xpm"
# define PLAYER_IMG_A "images/player_a.xpm"
# define ENEMY_IMG_1 "images/enemy/enemy_1.xpm"
# define ENEMY_IMG_2 "images/enemy/enemy_2.xpm"
# define ANGEL_IMG "images/enemy/angel.xpm"
# define WEAPON_IMG "images/weapon.xpm"
# define COLOR 0x00F000F0
# define BLACK 0x00000000

typedef struct s_sym
{
	int	C;
	int	P;
	int	E;
	int	zero;
	int	one;
}				t_sym;

typedef struct s_player {
	int		col;
	int		row;
	int		food;
}				t_player;

typedef struct s_move {
	bool	W;
	bool	A;
	bool	S;	
	bool	D;
}				t_move;

typedef struct s_data {
	void		*wall_img;
	void		*empty_img;
	void		*food_img;
	void		*exit_img;
	void		*player_img;
	void		*player_img_d;
	void		*player_img_a;
	void		*weapon_img;
	void		*enemy_img_1;
	void		*enemy_img_2;
	void		*angel_img;
	int			img_width;
	int			img_height;
	void		*mlx;
	void		*win;
	int			food_num;
	int			symbols_num;
	int			str_num;
	char		**map;
	t_player	player;
	t_move		move;
	bool		is_not_wall_exit;
	bool		is_weapon;
	int			for_demon_move;
	int			move_num;
	int			pixel;
}				t_data;

int		map_str_count(int fd, t_data *img, char *map);
int		ft_print_error(char *str);
int		ft_print_perror(char *str);
int		ft_printf(const char *str, ...);
int		close_exit(void);
void	ft_map_draw(t_data *img, int flag);
void	ft_string_put(t_data *img);
void	ft_game(t_data *img);
void	ft_move(t_data *img);
void	ft_img_init(t_data *img);
void	map_check(t_data *img);

#endif
