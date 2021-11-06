/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:43:01 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 13:58:31 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int sym, size_t n)
{
	size_t	i;	

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = sym;
		i++;
	}
	return (str);
}
