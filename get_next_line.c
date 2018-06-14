/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:28:09 by msefako           #+#    #+#             */
/*   Updated: 2018/06/12 19:26:01 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <time.h>
#include <fcntl.h>
#include <stdio.h>

int			get_next_line(const int fd, char **line)
{
	char	*buff;
	int		str_sz;
	int		i;

	buff = ft_memalloc(BUFF_SIZE);
	i = 0;
	str_sz = BUFF_SIZE;
	while (BUFF_SIZE == str_sz)
	{
		str_sz = read(fd, buff, BUFF_SIZE);
//		i = ft_strlen(buff) - 1;
		if (buff[ft_strlen(buff) -1] == '\0')
		{
			ft_bzero((void*)buff, ft_strlen(buff));
			break ;
		}
		ft_putstr(buff);
//		ft_strncat(line,buff, str_sz);
		i++;
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
