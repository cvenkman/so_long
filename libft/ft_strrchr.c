/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:43:35 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:50:51 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	unsigned int	i;

	i = 0;
	i = ft_strlen(str);
	while (*(unsigned char *)str)
		str++;
	while (i > 0)
	{
		if (*(unsigned char *)str == sym)
			return ((char *)str);
		str--;
		i--;
	}
	if (*(unsigned char *)str == sym)
		return ((char *)str);
	return (0);
}
