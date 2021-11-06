/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:43:05 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:50:41 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	while (*(unsigned char *)str)
	{
		if (*(unsigned char *)str == sym)
			return ((char *)str);
		str++;
	}
	if (sym == '\0' && *str == '\0')
		return ((char *)str);
	return (0);
}
