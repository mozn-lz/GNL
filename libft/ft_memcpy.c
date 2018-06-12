/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:36 by msefako           #+#    #+#             */
/*   Updated: 2018/05/31 16:45:16 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t size)
{
	char	*destblock;
	char	*srcblock;

	destblock = (char*)dest;
	srcblock = (char*)src;
	while (size--)
	{
		*destblock++ = *srcblock++;
	}
	return (dest);
}
