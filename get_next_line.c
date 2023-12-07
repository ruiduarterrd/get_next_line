/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarte.rrd <ruiduarte.rrd@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:55 by ruirodri          #+#    #+#             */
/*   Updated: 2023/12/06 14:16:11 by ruiduarte.r      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			bytes_read;

	if (!remainder)
		remainder = ft_strdup("");
	while (!(ft_strchr(remainder, '\n')))
	{
		bytes_read = ft_read_from_file(fd, &remainder);
		if (bytes_read <= 0)
			break ;
	}
	return (ft_get_line(&remainder));
}

int	main(void)
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
}
