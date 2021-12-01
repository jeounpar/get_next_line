/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:10 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:58:54 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//bzero, memmove - > X, strncpy -> X, strjoin

static int	free_buff(char **buff, char *line)
{
	int	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (buff[i] != NULL)
			free(buff[i]);
		i++;
	}
	free(line);
	return (0);
}

static void	ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	read_line(char *buff, char **line, int fd)
{
	char	c;
	int		i;
	int		eof;
	int		nl;

	i = 0;
	eof = 0;
	nl = 0;
	while (i < BUFFER_SIZE)
	{
		if (!read(fd, &c, 1))
		{
			eof = 1;
			break ;
		}
		if (c == '\n')
		{
			nl = 1;
			break ;
		}
		buff[i] = c;
		i++;
	}
	if (eof == 1)
	{
		line[0] = NULL;
		return (-1);
	}
	if (line[0][0] == 0)
		ft_strncpy(line[0], buff, i);
	else
		ft_strjoin(line, buff, i);
	if (nl == 0)
		return (ft_bzero(buff, BUFFER_SIZE));
	else
		return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	ft_bzero(line, BUFFER_SIZE + 1);
	if (buff[fd] == NULL)
	{
		buff[fd] = malloc(BUFFER_SIZE);
		if (buff[fd] == NULL)
		{
			free_buff(buff, line);
			return (NULL);
		}
	}
	while (read_line(buff[fd], &line, fd) != -1)
		;
	return (line);
}

