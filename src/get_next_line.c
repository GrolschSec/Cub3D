/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:37:33 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:35 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*clear_stash(char *stash)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
			i++;
	if (stash[i] == '\n')
		i++;
	tmp = ft_substr(stash, (unsigned int)i, ft_strlen(stash) - i);
	free(stash);
	stash = tmp;
	if (!stash[0])
		return (free(stash), NULL);
	return (stash);
}

char	*stash_to_line(char *stash)
{
	char	*line;
	char	*tmp;
	int		i;

	if (!stash || *stash == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
			i++;
	if (stash[i] == '\n' || stash[i] == '\0')
	{
		line = ft_substr(stash, 0, i);
		if (stash[i] == '\n')
		{
			tmp = ft_strjoin(line, "\n");
			free(line);
			line = tmp;
		}
	}
	if (!line)
		return (NULL);
	return (line);
}

char	*read_and_stash(char *stash, int fd)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(stash, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (free(buf), NULL);
		buf[ret] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	return (free(buf), buf = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = stash_to_line(stash);
	stash = clear_stash(stash);
	return (line);
}
