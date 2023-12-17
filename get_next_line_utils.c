/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruirodri < ruirodri@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:18 by ruiduarte.r       #+#    #+#             */
/*   Updated: 2023/12/17 13:25:46 by ruirodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		joined[i++] = s2[j++];
	if (s2[j] == '\n')
		joined[i++] = '\n';
	joined[i] = '\0';
	if (s1)
		free(s1);
	return (joined);
}

int	ft_clean(char *str)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	j = 0;
	aux = 0;
	while (str[i])
	{
		if (aux)
		{
			str[j] = str[i];
			j++;
		}
		if (str[i] == '\n')
			aux = 1;
		str[i++] = '\0';
	}
	return (aux);
}
