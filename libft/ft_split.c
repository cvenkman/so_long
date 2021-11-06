/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:06:07 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 15:35:35 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_free(char **arr, unsigned int word_count)
{
	unsigned int	i;

	i = 0;
	while (i < word_count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static unsigned int	ft_c_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			word_count++;
		}
	}
	return (word_count);
}

unsigned int	ft_arr_elem_len(char const *str, char c)
{
	unsigned int	arr_elem_len;

	arr_elem_len = 0;
	while (*str != c && *str)
	{
		arr_elem_len++;
		str++;
	}
	return (arr_elem_len);
}

static char	*ft_copy(char const *str, unsigned int arr_elem_len)
{
	char			*arr_elem;
	unsigned int	i;

	i = 0;
	arr_elem = malloc(sizeof(char) * (arr_elem_len + 1));
	if (!arr_elem)
		return (NULL);
	while (i < arr_elem_len)
	{
		arr_elem[i] = str[i];
		i++;
	}
	arr_elem[i] = '\0';
	return (arr_elem);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	word_count;

	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_c_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		arr[i] = ft_copy(s, ft_arr_elem_len(s, c));
		if (arr[i] == NULL)
			return (ft_malloc_free(arr, word_count));
		s = s + ft_arr_elem_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
