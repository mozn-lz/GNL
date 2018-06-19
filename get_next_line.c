/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:54:45 by msefako           #+#    #+#             */
/*   Updated: 2018/06/18 15:54:53 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int	ft_find_brk(char **brk_ln, char **line)
{
	int len;

	if (ft_strchr(*brk_ln, '\n') != NULL)
	{
		len = ft_strchr(*brk_ln, '\n') - *brk_ln;
		line[0] = ft_strsub(*brk_ln, 0, len);
		*brk_ln = ft_strchr(*brk_ln, '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*brk_ln);
	*brk_ln = NULL;
	return (0);
}

int	ft_read_fl(char **line, const int fd, char **brk_ln, char *str)
{
	char	*tmp;
	int		len;
	int		ret;

	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		str[ret] = '\0';
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, str);
		free(tmp);
		if (ft_strchr(line[0], '\n'))
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*brk_ln = ft_strdup(ft_strchr(line[0], '\n') + 1);
			tmp = ft_strdup(line[0]);
			free(line[0]);
			line[0] = ft_strsub(tmp, 0, len);
			free(tmp);
			break ;
		}
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		*str;
	static char	*brk_ln = NULL;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (brk_ln != NULL)
		if (ft_find_brk(&brk_ln, &line[0]))
			return (1);
	str = ft_strnew(BUFF_SIZE);
	if ((ret = ft_read_fl(&line[0], fd, &brk_ln, str)) == -1)
		return (-1);
	free(str);
	if (ret == 0 && ft_strlen(line[0]) == 0)
		return (0);
	return (1);
}
