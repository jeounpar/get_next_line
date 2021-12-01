/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:30:13 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/01 12:54:00 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strchridx(char *s, int c);
int		ft_bzero(void *s, size_t n);
char	*ft_strjoin(char **line, char *buff, int len);
char	*get_next_line(int fd);

#endif
