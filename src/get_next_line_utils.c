/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:22:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:25 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

//M
char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	length;
	size_t	i;
	char	*str;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}

//M
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
	{
		str = ((char *)malloc(sizeof(char) * 1));
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - (size_t) start;
	j = 0;
	i = (size_t)start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && len--)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
