#include "libft/libft.h"
#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	char *buff[BUFF_SIZE];
	int str;

	while (string)
	{
		str = read(fd, *buff, BUFF_SIZE);
		while(buff)
		{
			if(buff[i] == '\n')
			{
			/*
			 *	end of line
			 *	start new line			
			*/
		 		ft_strncat(*line, buff[i], i);
				printf(**line);
			}
			else
			{
			/*	add buffer to current line	*/
				ft_strncat(*line, buff, BUFF_SIZE);
			}

		}
	}
	return (**line);
}

int		main()
{
	char *line;

	get_next_line(fd, &line);
	return (0);
}
