/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:40:23 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/16 13:16:13 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_treat(int fd, char **str, char *buff, ssize_t bytes_read)
{
	char	*aux;

	aux = 0;
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (!(str[fd]))
			str[fd] = ft_calloc(sizeof(char), BUFFER_SIZE);
		aux = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
}

static void	*ft_save(char **str, int len)
{
	char	*line;
	char	*aux;

	if ((*str)[len] == '\n')
	{
		line = ft_substr(*str, 0, len + 1);
		aux = ft_strdup(*str + len + 1);
		free(*str);
		*str = aux;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	return (line);
}

static void	*ft_get_line(char **str)
{
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	line = ft_save(str, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[FILE_SIZE];
	char		*buff;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buff);
		return (0);
	}
	ft_treat(fd, str, buff, bytes_read);
	if (!bytes_read && (!str[fd] || !*str[fd]))
		return (0);
	line = ft_get_line(&(str[fd]));
	return (line);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	n;

	n = nitems * size;
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < n)
		((char *)ptr)[i++] = '\0';
	return (ptr);
}
