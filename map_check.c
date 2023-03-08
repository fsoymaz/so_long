/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:12 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/08 14:46:36 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	check_map_chars(char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != '\n')
	{
		write(2, "Invalid character in map.\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	check_arg(void)
{
	map_info();
	if (t_map.chk_player != 1 || t_map.exit_count != 1 || t_map.coin_count == 0)
	{
		write (2, "Error: Invalid map\n", 19);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	check_arg();
}
