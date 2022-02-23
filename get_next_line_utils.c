/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:40:47 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/15 14:22:14 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s,
			unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s == '\0')
		return (0);
	if (ft_strlen(s) < len)
		new = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	else
		new = malloc(sizeof(*s) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start)
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str2)
		return (0);
	while (s1[i])
	{
		str2[i] = ((char *)s1)[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

unsigned long int	ft_strlen(char const	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	j = 0;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
