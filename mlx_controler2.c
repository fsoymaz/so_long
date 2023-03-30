/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatihsoymaz <fatihsoymaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 05:01:56 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/30 17:49:56 by fatihsoymaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

void	write_s(t_mlx *mlx, int step)
{
	char	*v;
	char	*a;
	char	*b;

	v = ft_itoa(step);
	a = ft_itoa(t_map.current_coin);
	b = ft_itoa(t_map.coin_count);
	mlx_string_put(mlx->init, mlx->win, 5, 20, 0xf5fffa, "step: ");
	mlx_string_put(mlx->init, mlx->win, 5, 40, 0xf5fffa, "coin count: ");
	mlx_string_put(mlx->init, mlx->win, 100, 40, 0x000080, b);
	mlx_string_put(mlx->init, mlx->win, 45, 20, 0x97ffff, v);
	mlx_string_put(mlx->init, mlx->win, 83, 40, 0x97ffff, a);
	free(v);
	free(a);
	free(b);
}

int	ft_movement(int key, t_mlx *mlx)
{
	static int	step;

	if (key != 0 && key != 2 && key != 1 && key != 13 && key != 53)
		return (1);
	if (key == 53)
		exit(0);
	move(t_map.map, &step, (key == 2) - (key == 0), (key == 1) - (key == 13));
	if ((t_map.exit_col != t_map.p_col || t_map.exit_row != t_map.p_row))
		t_map.map[t_map.exit_row][t_map.exit_col] = 'E';
	if (t_map.exit_col == t_map.p_col && t_map.exit_row == t_map.p_row)
		exit_checker(mlx);
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
	ft_putstr("step:0\n");
	write_s(mlx, 0);
	mlx_hook(mlx->win, 2, 1L << 0, &ft_movement, mlx);
	mlx_hook(mlx->win, 17, 0, &ft_exit, mlx);
	mlx_loop(mlx->init);
}
