/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:39:31 by msefako           #+#    #+#             */
/*   Updated: 2018/06/06 03:24:36 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dlen;
	size_t	size;

	i = 0;
	dlen = 0;
	size = destsize;
	while (dest[dlen] && size-- != 0)
		dlen++;
	size = destsize - dlen;
	if (size == 0)
		return (dlen + ft_strlen((char*)src));
	while (src[i] != '\0')
	{
		if (size != 1)
		{
			dest[dlen + i] = src[i];
			size--;
		}
		i++;
		dest[dlen + i] = '\0';
	}
	return (dlen + i);
}
