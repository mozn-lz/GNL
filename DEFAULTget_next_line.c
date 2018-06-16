/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:28:09 by msefako           #+#    #+#             */
/*   Updated: 2018/06/16 09:59:56 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <time.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strfintr(const char *s, char c)
{
	char	*sret;
	int		i;

	i = 0;
	while (s)
	{
		if (s[i] == c)
			if ((sret = strndup(s, i)))
				return (sret);
		i++;
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	char	*buff;
	char	*str;
	int		str_sz;
	int		i, j;

	buff = ft_memalloc(BUFF_SIZE);
	str_sz = BUFF_SIZE;
	while (BUFF_SIZE == str_sz)
	{
		i = 0;
//	j = 1;
		str_sz = read(fd, buff, BUFF_SIZE);
		while (buff[i])
		{
			if (buff[i] == '\n' )
			{
			//	buff[i] = '\0';
				ft_putchar('\n');
			}
			i++;
		}
		printf("%s", buff);
//		ft_putstr(*line);
	}
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1) return (0);
		char *line;
	int fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("a");
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
