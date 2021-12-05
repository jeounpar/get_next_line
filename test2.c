#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s) + 1;
	tmp = (char *)malloc(size * sizeof(char));
	if (tmp == NULL)
		return (0);
	while (s[i] != '\0')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int main(void)
{
	static char *buff[10];
	int	len;

	buff[1] = ft_strdup("");
	// if (buff[1] == NULL)
	// 	printf("NULL\n");
	len = ft_strlen(buff[1]);
	printf("%d\n", len);
	return 0;
}