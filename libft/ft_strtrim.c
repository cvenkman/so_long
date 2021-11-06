/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:38:16 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 15:36:05 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_all_set(void)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

static char	*ft_ft(unsigned int len, char const *s1)
{
	unsigned int	t;
	char			*str;

	t = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	s1 = s1 - (len - 1);
	while (t < len)
	{
		str[t] = s1[t];
		t++;
	}
	str[t] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	set_count_begin;
	unsigned int	set_count_end;
	unsigned int	len;

	set_count_begin = 0;
	set_count_end = 0;
	if (!s1 || !set)
		return (NULL);
	len = (unsigned int)ft_strlen(s1);
	while (*s1 && ft_set(*s1, set) != 0)
	{
		set_count_begin++;
		s1++;
	}
	if (set_count_begin == len)
		return (ft_all_set());
	while (*s1)
		s1++;
	s1--;
	while (ft_set(*s1, set) != 0)
	{
		set_count_end++;
		s1--;
	}
	return (ft_ft((len - (set_count_begin + set_count_end)), s1));
}
