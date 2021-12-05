/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:13 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/05 17:37:01 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#define OPEN_MAX 1024
#define BUFFER_SIZE 10

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s, int n);
char	*ft_strjoin(char *buff, char *s2);
char	*get_next_line(int fd);

#endif
