/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:10 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/05 23:07:52 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(char *buff, int fd)
{
	int		read_size;
	char	*tmp;

	read_size = 42;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	while (read_size > 0)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_size] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (ft_strchr(buff, '\n') != 0)
			break ;
	}
	free(tmp);
	return (buff);
}

static char	*get_next_buff(char *buff)
{
	char	*next_buff;
	int		idx;
	int		i;

	idx = 0;
	while (buff[idx] != '\0' && buff[idx] != '\n')
		idx++;
	if (buff[idx] == '\0')
	{
		free(buff);
		return (NULL);
	}
	next_buff = malloc((ft_strlen(buff) - idx + 1));
	idx++;
	i = 0;
	while (buff[idx + i])
	{
		next_buff[i] = buff[idx + i];
		i++;
	}
	next_buff[i] = '\0';
	free(buff);
	return (next_buff);
}

static void	new_line_two(char *buff, char **line)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[0][i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[0][i] = '\n';
		i++;
	}
	line[0][i] = '\0';
}

static char	*new_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		line = (char *)malloc((i + 2) * sizeof(char));
	else
		line = (char *)malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	new_line_two(buff, &line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buff[fd] = read_file(buff[fd], fd);
	if (buff[fd] == NULL)
		return (NULL);
	if (buff[fd][0] == '\0')
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	line = new_line(buff[fd]);
	if (line == NULL)
		return (NULL);
	buff[fd] = get_next_buff(buff[fd]);
	return (line);
}
