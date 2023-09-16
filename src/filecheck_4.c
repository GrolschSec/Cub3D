/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:00:00 by yaassila          #+#    #+#             */
/*   Updated: 2023/09/16 13:00:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*find_start_of_map(char *str)
{
	char	*line;

	line = str;
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			line = str;
		}
		else if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
			str = ft_strchr(str, '\n');
		else if (*str != ' ')
			return (line);
		else
			str++;
	}
	return (NULL);
}
