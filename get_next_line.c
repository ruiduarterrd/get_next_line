/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruirodri < ruirodri@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:55 by ruirodri          #+#    #+#             */
/*   Updated: 2023/12/17 13:16:00 by ruirodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*next_line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_strjoin(0, buffer);
	if (ft_clean(buffer) > 0)
		return (next_line);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || (bytes == 0 && (*next_line == '\0')))
	{
		free(next_line);
		return (NULL);
	}
	while (bytes > 0)
	{
		next_line = ft_strjoin(next_line, buffer);
		if (ft_clean(buffer) > 0)
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (next_line);
}

/* int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	char *line;
	int i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d -> %s\n", i++, line);
		free(line);
	}
	close(fd);
	return (0);
} */
