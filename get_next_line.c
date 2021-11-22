/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:10 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/22 02:28:12 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//bzero, memmove - > X, strncpy -> X, strjoin
const int BUFFER_SIZE = 1000;

static int	free_buff(char *buff[OPEN_MAX])
{
	int	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (buff[i] != NULL)
			free(buff[i]);
		i++;
	}
	return (0);
}

static int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strndup(char *src, size_t n)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	tmp = (char *)malloc(size * sizeof(char));
	if (tmp == NULL)
		return (0);
	while (src[i] != '\0' && i < n)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;
	int			len;
	int			idx;

	if (buff[fd] == NULL)
	{
		buff[fd] = malloc(BUFFER_SIZE + 1);
		if (buff[fd] == NULL)
		{
			free_buff(&buff[OPEN_MAX]);
			return (NULL);
		}
	}
	len = read(fd, buff[fd], BUFFER_SIZE);
	buff[fd][BUFFER_SIZE] = '\0';
	idx = ft_strchridx(buff[fd], '\n');
	line = ft_strndup(buff[fd], idx);
	return (line);
}

// int	get_int(int num)
// {
// 	static int n = 0;

// 	n++;
// 	num = n;
// 	return (num);
// }
