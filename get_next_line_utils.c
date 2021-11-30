/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:17 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/09 01:30:18 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memmove(char *dest, char *src, int n)
{
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		while (n--)
			*dest++ = *src++;
	else
		while (n--)
			*(dest + n) = *(src + n);
	return (dest);
}

int	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (1);
}

static void	join_str(char *str, char *line, char *buff, int size)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (j < size)
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char **line, char *buff, int size)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	while (line[0][i] != '\0')
		i++;
	len = i + size + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	join_str(str, line[0], buff, size);
	free(line[0]);
	*line = str;
	return (str);
}
