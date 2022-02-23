/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:52:33 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/15 14:23:55 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FILE_SIZE 4096

# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*
---GET_NEXT_LINE
*/

/*
	ft_get_next_line
*/

char				*get_next_line(int fd);
void				*ft_calloc(size_t nitems, size_t size);

/*
	ft_get_next_line_utils
*/

char				*ft_substr(char const *s,
						unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned long int	ft_strlen(char const	*s);

#endif
