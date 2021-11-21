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

//bzero, memmove - > X, strncpy -> X, strjoin

int	free_buff(char *buff[_SC_OPEN_MAX])
{
	int	i;

	i = 0;
	while (i < _SC_OPEN_MAX)
	{
		if (buff[i] != NULL)
			free(buff[i]);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	const int BUFFER_SIZE = 10;
	static char *buff[_SC_OPEN_MAX];
	char	*line;
	
	//buff[BUFFER_SZIE]가 할당이 되어 있는지 아닌지 체크
	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	if (buff[fd] == NULL)
	{
		buff[fd] = malloc(BUFFER_SIZE + 1);
		if (buff[fd] == NULL)
			return (free_buff(buff[_SC_OPEN_MAX]));
	}
	// 버퍼 사이즈 만큼 계속 읽으면 언제 할당하고 리턴??
	while (read(fd, buff[fd], BUFFER_SIZE))
	{
		
	}
	
}

// int	get_int(int num)
// {
// 	static int n = 0;

// 	n++;
// 	num = n;
// 	return (num);
// }
