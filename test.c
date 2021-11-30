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
	line = get_next_line(fd);
	//printf("%s\n", line);
	close(fd);
	return(0);
}