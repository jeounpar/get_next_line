#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int main(void)
{
	int fd;

	fd = open("./test.txt", O_RDONLY);
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	close(fd);
	return(0);
}
