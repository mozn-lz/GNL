/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 03:10:25 by msefako           #+#    #+#             */
/*   Updated: 2018/06/06 00:29:33 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char		*fresh;
	char		*s;
	size_t		i;

	s = (char*)str;
	i = 0;
	if (!str || len == 0)
		return (NULL);
	if (len > 0)
	{
		fresh = ft_strnew(len);
		if (fresh)
		{
			while (i < len)
			{
				fresh[i] = s[start + i];
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
