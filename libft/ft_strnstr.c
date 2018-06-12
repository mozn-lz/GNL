/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:12:04 by msefako           #+#    #+#             */
/*   Updated: 2018/06/02 15:34:44 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t counter;

	if (*needle == '\0')
		return ((char *)stack);
	counter = 0;
	while (*stack && len)
	{
		if (*stack == needle[counter])
			counter++;
		else
			counter = 0;
		if (needle[counter] == '\0')
			return ((char*)stack - counter + 1);
		stack++;
		len--;
	}
	return (NULL);
}
