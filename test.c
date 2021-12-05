#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

void	sss(char **backup)
{
	if (!*backup)
		printf("asd\n");
}

int main(void)
{
	int fd;
	int len;
	int chk;
	char *line;
	static char *s[10];

	sss(&s[1]);

	fd = open("./test.txt", O_RDONLY);
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	printf("final = %s\n", get_next_line(fd));
	close(fd);
	return(0);
}
