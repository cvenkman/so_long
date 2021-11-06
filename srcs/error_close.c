#include "../includes/so_long.h"

int	ft_print_error(char *str)
{
	ft_putstr_fd(str, 0);
	ft_putstr_fd("\n", 0);
	exit (EXIT_FAILURE);
}

int	ft_print_perror(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

int	close_exit(void)
{
	ft_putstr_fd("Exit\n", 0);
	exit (EXIT_SUCCESS);
	return (1);
}
