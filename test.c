#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int len;
	int chk;
	char buf[100];
	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		chk = read(fd, buf, 10);
		if (!chk)
			break;
		len += chk;
	}
	close(fd);
	printf("%d\n", len);
	return(0);
}