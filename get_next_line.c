/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:10 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/05 17:49:36 by jeounpar         ###   ########.fr       */
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

static int	find_nl_idx(char *buff)
{
	int	idx;

	idx = 0;
	while (buff[idx] != '\0')
	{
		if (buff[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*cut_buff(char **buff, char **line, int idx)
{
	char	*tmp;

	buff[0][idx] = '\0';
	*line = ft_strdup(buff[0], 0);
	//printf("line = %s\n", *line);
	tmp = ft_strdup(buff[0], idx + 1);
	//printf("\ntmp = %s\n\n", tmp);
	free(buff[0]);
	buff[0] = tmp;
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;
	char		tmp_buff[BUFFER_SIZE + 1];
	int			t_size;
	int			nl_idx;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	nl_idx = -2;
	while (nl_idx < 0)
	{
		t_size = read(fd, tmp_buff, BUFFER_SIZE);
		if (t_size < 1)
			break ;
		tmp_buff[t_size] = '\0';
		buff[fd] = ft_strjoin(buff[fd], tmp_buff);
		nl_idx = find_nl_idx(buff[fd]);
		if (nl_idx >= 0)
			return (cut_buff(&buff[fd], &line, nl_idx));
	}
	if (t_size < 0)
		return (NULL);
}

