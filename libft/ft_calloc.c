/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:42:12 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:31:42 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*a;
	size_t	i;
	size_t	mem_size;

	i = 0;
	mem_size = n * size;
	a = malloc(mem_size);
	if (!a)
		return (NULL);
	while (i < mem_size)
	{
		*(char *)(a + i) = 0;
		i++;
	}
	return (a);
}
