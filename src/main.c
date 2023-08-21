/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:04:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/21 19:03:52 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_putstr_fd("Error\nNot enough arguments", 1);
	return (0);
}
