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

int			get_next_line(const int fd, char **line)
{
	char	*buff;
	int		str;
	int		i;

	buff = NULL;
	i = 0;
	printf("B1\n");
	while (fd)
	{
	printf("B2\n");
		str = read(fd, buff, BUFF_SIZE);
		i = 0;
		if (str)
		{
	printf("B3\n");
			while (buff)
			{
				/*	search for '\n' charecter	*/
				if (buff[i] == '\n')
					break ;
				i++;
			}
	printf("B4\n");
	printf("%d ", i)
			if(buff[i] == '\n')
			{
			/*
			 *	end of line
			 *	start new line
			*/
	printf("B5\n");
				ft_strncat(*line, buff, i);
	printf("B6\n");
				buff[i] = '\0';
				line++;
			}
			else
			{
			/*	add buffer to current line	*/
				ft_strncat(*line, buff,BUFF_SIZE);
			}
			buff++;
			i++;
			printf("%d:", i);
		}
		else
			printf("read faiiled\n");
		break ;
	}
	return (**line);
}



int	main()
{

	 clock_t start, end;
	 double time_spent;

     start = clock();
	int i;
	int fd = open("large_file", O_RDONLY);
	char	**line;
	line = malloc(100000);
	*line = malloc(100000);
	i = 1;
	int count = 0;
	printf("A\n");
	while (count != 783)
	{
	printf("A\n");
		count++;
		i = get_next_line(fd, line);
		printf("%d: Buff: {%d}  len: %d [%s]\n",i ,BUFF_SIZE,ft_strlen(*line), *line);
	}
	 end = clock();


	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
 	printf("%f\n",time_spent);
	return(0);
}
/*
int		main()
{
	char *line;

	get_next_line(fd, &line);
	return (0);
}
*/
