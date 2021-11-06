/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:26:52 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:26:58 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	if (ft_strlen(str) > start)
	{
		while (str[start] && len > 0)
		{
			sub_str[i] = str[start];
			i++;
			start++;
			len--;
		}
	}
	sub_str[i] = '\0';
	return (sub_str);
}
