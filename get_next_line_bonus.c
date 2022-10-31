/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:27:48 by elakhfif          #+#    #+#             */
/*   Updated: 2022/10/31 09:27:53 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *rest)
{
	char	*line;
	int		index;
	int		i;

	i = 0;
	if (ft_strlen(rest) <= 0)
		return (NULL);
	index = find_new_line(rest);
	if (index == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_rest(char *rest)
{
	int		len;
	int		index;
	char	*tmp;

	if (!rest)
		return (NULL);
	len = ft_strlen(rest);
	index = find_new_line(rest);
	if (index != -1)
	{
		tmp = ft_substr(rest, (index + 1), (len - index - 1));
		free (rest);
		rest = tmp;
		return (rest);
	}
	free (rest);
	return (NULL);
}

char	*ft_read(int fd, char *buff, char *rest)
{
	char	*tmp;
	int		n;

	n = 0;
	while (find_new_line(rest) == -1)
	{
		n = read (fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(rest, buff);
			if (rest)
				free(rest);
			rest = NULL;
			rest = tmp;
		}
		else
			break ;
	}
	free (buff);
	buff = NULL;
	if (n == -1)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*rest[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rest[fd] = ft_read(fd, buff, rest[fd]);
	line = ft_line(rest[fd]);
	rest[fd] = ft_rest(rest[fd]);
	return (line);
}
