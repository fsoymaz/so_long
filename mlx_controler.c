/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:07:52 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/11 03:58:25 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_mlx *map)
{
	map->p_p = "./xpms/player.xpm";
	map->w_p = "./xpms/wall.xpm";
	map->c_p = "./xpms/coin.xpm";
	map->g_p = "./xpms/door.xpm";
	map->f_p = "./xpms/background.xpm";
	map->w = mlx_xpm_file_to_image(map->init, map->w_p, &map->x, &map->y);
	map->p = mlx_xpm_file_to_image(map->init, map->p_p, &map->x, &map->y);
	map->c = mlx_xpm_file_to_image(map->init, map->c_p, &map->x, &map->y);
	map->g = mlx_xpm_file_to_image(map->init, map->g_p, &map->x, &map->y);
	map->f = mlx_xpm_file_to_image(map->init, map->f_p, &map->x, &map->y);
}

void	img_printer(t_mlx *mlx, char c)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, mlx->x1, mlx->y1);
	if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, mlx->x1, mlx->y1);
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c, mlx->x1, mlx->y1);
	if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g, mlx->x1, mlx->y1);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, mlx->x1, mlx->y1);
	}
}

void	put_img(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = t_map.p_col * 64;
	y = t_map.p_row * 64;
	i = 0;
	mlx->y1 = 0;
	while (map[i] != NULL)
	{
		j = 0;
		mlx->x1 = 0;
		while (map[i][j] != '\0')
		{
			img_printer(mlx, map[i][j]);
			j++;
			mlx->x1 += 64;
		}
		mlx->y1 += 64;
		i += 1;
	}
}

void	mlx_control(t_mlx *mlx)
{
	int		l;
	int		c;

	l = t_map.l_cnt * 64;
	c = t_map.w_cnt * 64;
	mlx->init = mlx_init();
	xpm_to_img(mlx);
	mlx->win = mlx_new_window(mlx->init, c, l, "so_long");
	put_img(mlx, t_map.map);
	mlx_loop(mlx->init);
}
