/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 05:01:56 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/13 20:14:57 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_checker(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->m, mlx->x1, mlx->y1);
	if (t_map.current_coin == t_map.coin_count)
		close_with();
}

void	move(char **map, int *step, int dx, int dy)
{
	if (map[t_map.p_row + dy][t_map.p_col + dx] != '1')
	{
		if (map[t_map.p_row + dy][t_map.p_col + dx] == 'C')
			t_map.current_coin++;
		map[t_map.p_row][t_map.p_col] = '0';
		map[t_map.p_row + dy][t_map.p_col + dx] = 'P';
		t_map.p_row += dy;
		t_map.p_col += dx;
		ft_putstr("step:");
		ft_putnbr((*step)++);
		ft_putstr("\n");
	}
}

void	write_s(t_mlx *mlx, int step)
{
	char	*v;

	v = ft_itoa(step);
	mlx_string_put(mlx->init, mlx->win, 5, 20, 0xffff99, "step: ");
	mlx_string_put(mlx->init, mlx->win, 45, 20, 0xffff99, v);
	free(v);
}

int	ft_movement(int key, t_mlx *mlx)
{
	static int	step;

	if (key != 0 && key != 2 && key != 1 && key != 13 && key != 53)
		return (1);
	move(t_map.map, &step, (key == 2) - (key == 0), (key == 1) - (key == 13));
	if ((t_map.gate_col != t_map.p_col || t_map.gate_row != t_map.p_row))
		t_map.map[t_map.gate_row][t_map.gate_col] = 'E';
	if (t_map.gate_col == t_map.p_col && t_map.gate_row == t_map.p_row
		&& t_map.current_coin == t_map.coin_count)
		exit_checker(mlx);
	if (key == 53)
	{
		close_with();
	}
	put_img(mlx, t_map.map);
	write_s(mlx, step);
	return (0);
}

void	mlx_control(t_mlx *mlx)
{
	int	l;
	int	c;

	l = t_map.l_cnt * 64;
	c = t_map.w_cnt * 64;
	mlx->init = mlx_init();
	xpm_to_img(mlx);
	mlx->win = mlx_new_window(mlx->init, c, l, "so_long");
	put_img(mlx, t_map.map);
	mlx_hook(mlx->win, 2, 0, &ft_movement, mlx);
	mlx_hook(mlx->win, 17, 0, &close_with, mlx);
	mlx_loop(mlx->init);
}
