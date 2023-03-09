/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:56:24 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/09 17:52:16 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	ber_check(argv);
	check_arg(argv);
	map_info(argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1200, 1200, "so_long");
	data.path = "./xpms/player/player.xpm";
	data.img = mlx_xpm_file_to_image(data.mlx, data.path, &data.i_w, &data.i_h);
	data.x = t_map.p_row * 64;
	data.y = t_map.p_col * 64;
	data.map = NULL;
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);
	mlx_hook(data.win, 2, 1L << 0, &key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, close_with, &data);
	mlx_loop(data.mlx);
}
