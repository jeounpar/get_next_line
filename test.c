#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int main(void)
{
	int fd;
	int len;
	int chk;
	char *line;

	fd = open("./test.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
	}
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	system("leaks a.out");
	close(fd);
	return(0);
}
