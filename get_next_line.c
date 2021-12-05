/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:10 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/05 19:47:09 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//bzero, memmove - > X, strncpy -> X, strjoin

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

char	*cut_buff(char **buff, int idx)
{
	char	*tmp;
	char	*line;
	
	buff[0][idx] = '\0';
	line = ft_strdup(buff[0], 0);
	printf("line = %s\n", line);
	// if ((ft_strlen(buff[0]) + idx + 1) == 0)
	// {
	// 	free(buff[0]);
	// 	buff[0] = NULL;
	// 	return (NULL);
	// }
	tmp = ft_strdup(buff[0], idx + 1);
	free(buff[0]);
	buff[0] = tmp;
	printf("[buff]\n---------\n%s\n---------\n", buff[0]);
	return (line);
}

char	*handling_exep(char **buff, int t_size)
{
	int		idx;
	char	*line;
	
	if (t_size == -1)
		return (NULL);
	idx = find_nl_idx(buff[0]);
	if (buff[0] != NULL && idx >= 0)
	{
		printf("2\n");
		printf("idx : %d\n", idx);
		return (cut_buff(buff, idx));
	}
	else if (buff[0] != NULL)
	{
		line = ft_strdup(buff[0], 0);
		free(buff[0]);
		buff[0] = NULL;
		return (line);
	}
	line = ft_strdup("", 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		tmp_buff[BUFFER_SIZE + 1];
	int			t_size;
	int			nl_idx;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	t_size = read(fd, tmp_buff, BUFFER_SIZE);
	while (t_size > 0)
	{
		tmp_buff[t_size] = '\0';
		buff[fd] = ft_strjoin(buff[fd], tmp_buff);
		nl_idx = find_nl_idx(buff[fd]);
		if (nl_idx >= 0)
			return (cut_buff(&buff[fd], nl_idx));
		t_size = read(fd, tmp_buff, BUFFER_SIZE);
	}
	printf("[buff]\n---------\n%s\n---------\n", buff[fd]);
	return (handling_exep(&buff[fd], t_size));
}

