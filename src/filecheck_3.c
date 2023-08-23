/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:23:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/23 12:25:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	find_end_of_map(char *str, int len)
{
	len--;
	while (len != 0 && !ft_isprint(str[len - 1]))
		len--;
	str[len] = '\0';
}
