/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:56:24 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/13 20:00:13 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		write (1, "ERROR\n", 6);
		exit(1);
	}
	ber_check(argv);
	check_arg(argv);
	if (t_map.l_cnt > 128 || t_map.w_cnt > 128)
		exit(1);
	path_checker();
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx_control(mlx);
}
