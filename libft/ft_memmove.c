/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:42:57 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 14:15:35 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	char	*new_dest;
	char	*new_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	new_dest = (char *)dest;
	new_src = (char *)src;
	if (new_src < new_dest)
	{
		while (n-- > 0)
			new_dest[n] = new_src[n];
		return (new_dest);
	}
	return (ft_memcpy(dest, src, n));
}
