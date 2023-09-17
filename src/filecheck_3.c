/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:23:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 15:00:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	find_end_of_map(char *str, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && (!ft_isprint(str[i]) || str[i] == ' '))
		i--;
	str[i + 1] = '\0';
}

int	check_color_char(char *loc)
{
	int	i;

	i = -1;
	while (loc[++i] && loc[i] != '\n')
	{
		if (!ft_isdigit(loc[i]) && loc[i] != ' ' && loc[i] != ',')
			return (0);
	}
	return (1);
}

int	is_nb_formatted(char *loc, char end)
{
	int	i;

	i = 0;
	while (loc[i] == ' ')
		i++;
	if (!ft_isdigit(loc[i]))
		return (0);
	while (ft_isdigit(loc[i]))
		i++;
	while (loc[i] == ' ')
		i++;
	if (loc[i] != end)
		return (0);
	return (i + 1);
}

int	check_color(char *loc)
{
	int	i;

	if (!check_color_char(loc))
		return (0);
	i = is_nb_formatted(loc, ',');
	if (!i)
		return (0);
	loc += i;
	i = is_nb_formatted(loc, ',');
	if (!i)
		return (0);
	loc += i;
	i = is_nb_formatted(loc, '\n');
	if (!i)
		return (0);
	return (1);
}

int	str_to_rgb(const char *str, int *num)
{
	long long	nb;

	nb = 0;
	while (*str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nb > (LLONG_MAX - (*str - '0')) / 10)
			return (0);
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (nb < 0 || nb > 255)
		return (0);
	*num = (int)nb;
	return (1);
}
