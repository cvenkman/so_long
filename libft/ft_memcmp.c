/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:42:48 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 13:52:18 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *str1, void const *str2, size_t n)
{
	size_t	i;
	char	*new_str1;
	char	*new_str2;

	new_str1 = (char *)str1;
	new_str2 = (char *)str2;
	i = 0;
	while (i < n)
	{
		if (new_str1[i] != new_str2[i])
			return ((unsigned char)new_str1[i] - (unsigned char)new_str2[i]);
		i++;
	}
	return (0);
}
