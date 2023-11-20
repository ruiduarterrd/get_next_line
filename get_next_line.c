/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruirodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:55 by ruirodri          #+#    #+#             */
/*   Updated: 2023/11/18 21:43:03 by ruirodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
	// so pode ser usada dentro da funcao get_next_line
	static t_list	*list;
	char			*next_line;
	
	list = NULL;
	// read(int fildes, void *buffer, size_t nbytes); #include <unistd.h>
	// verifica se o ficheiro pode ser aberto, caso nao de read retorna -1
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	
}

int	main(void)
{
	
	return (0);
}
