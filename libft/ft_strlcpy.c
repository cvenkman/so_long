/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:43:17 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:22:58 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*src2;

	i = 0;
	src2 = (char *)src;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && *(char *)src)
		{
			dest[i] = *(char *)src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src2));
}
