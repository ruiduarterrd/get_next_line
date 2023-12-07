/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarte.rrd <ruiduarte.rrd@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:18 by ruiduarte.r       #+#    #+#             */
/*   Updated: 2023/12/06 14:05:33 by ruiduarte.r      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	p = str;
	while (s1 && *s1)
		*p++ = *s1++;
	while (s2 && *s2)
		*p++ = *s2++;
	*p = '\0';
	return (str);
}

char	*ft_get_line(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*tmp;

	newline_pos = strchr(*remainder, '\n');
	if (newline_pos != NULL)
	{
		*newline_pos = '\0';
		line = ft_strdup(*remainder);
		tmp = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = tmp;
		return (line);
	}
	else if ((*remainder)[0] != '\0')
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}

int	ft_read_from_file(int fd, char **remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = tmp;
	}
	return (bytes_read);
}
