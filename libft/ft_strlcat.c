/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:43:13 by cvenkman          #+#    #+#             */
/*   Updated: 2021/04/29 12:18:05 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	len = ft_strlen(src);
	while (dest[i] && size > 0)
	{
		i++;
		len++;
		size--;
	}
	if (size > 0)
	{
		while (size > 1 && src[u])
		{
			dest[i] = src[u];
			i++;
			u++;
			size--;
		}
		dest[i] = '\0';
	}
	return (len);
}
