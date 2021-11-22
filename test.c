#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	int len;
	int chk;
	char buf[100];
	char *line;
	fd = open("./test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	printf("%d\n", len);
	printf("%d\n", OPEN_MAX);
	return(0);
}