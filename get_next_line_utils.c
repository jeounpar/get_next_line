/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:17 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/05 17:43:07 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s, int idx)
{
	char *str;
	int size;
	int i;

	size = ft_strlen(s) + 1;
	str = (char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (s[idx] != '\0')
	{
		str[i] = s[idx];
		idx++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = 0;
	while (dest[i] && i < size)
		i++;
	while (src[idx] && (i + idx + 1) < size)
	{
		dest[i + idx] = src[idx];
		idx++;
	}
	if (i < size)
		dest[i + idx] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (src[cnt] != '\0')
		cnt++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (cnt);
}


char	*ft_strjoin(char *buff, char *s2)
{
	char	*str;
	int		buff_len;
	int		s2_len;

	if (buff == NULL)
		buff = ft_strdup("", 0);
	buff_len = ft_strlen(buff);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((buff_len + s2_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, buff, buff_len + 1);
	free(buff);
	ft_strlcat(str, s2, buff_len + s2_len + 1);
	return (str);
}
