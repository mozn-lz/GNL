/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:11:16 by msefako           #+#    #+#             */
/*   Updated: 2018/05/31 15:41:59 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *stack, const char *needle)
{
	unsigned int hc;
	unsigned int nc;
	unsigned int i;

	hc = 0;
	nc = 0;
	i = ft_strlen((char*)needle);
	if (i == 0)
		return ((char*)stack);
	while (stack[hc])
	{
		while (needle[nc] == stack[hc + nc])
		{
			if (nc == i - 1)
				return ((char*)stack + hc);
			nc++;
		}
		nc = 0;
		hc++;
	}
	return (0);
}
