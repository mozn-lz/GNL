#include "get_next_line.h"

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
