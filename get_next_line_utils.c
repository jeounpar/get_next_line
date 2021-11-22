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

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t n)
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
}

int	ft_strchridx(char *s, int c)
{
	unsigned char	cc;
	char			*tmp;
	int				i;

	i = 0;
	tmp = (char *)s;
	cc = (unsigned char)c;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == cc)
			return (i);
		i++;
	}
	if (tmp[i] == cc)
		return (i);
	return (-1);
}

static void	join_str(char *str, char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s1_str;
	char	*s2_str;

	s1_str = (char *)s1;
	s2_str = (char *)s2;
	i = 0;
	while (s1_str[i] != '\0')
	{
		str[i] = s1_str[i];
		i++;
	}
	j = 0;
	while (s2_str[j] != '\0')
	{
		str[i] = s2_str[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	len = i + j + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	join_str(str, s1, s2);
	return (str);
}
