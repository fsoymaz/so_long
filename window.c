/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:39:12 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/09 17:46:40 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	close_with(void)
{
	exit(1);
	return (0);
}

void	move_player(t_data *data, int x, int y)
{
	data->x = x;
	data->y = y;
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		move_player(data, data->x, data->y - 10);
	else if (keycode == 0)
		move_player(data, data->x - 10, data->y);
	else if (keycode == 1)
		move_player(data, data->x, data->y + 10);
	else if (keycode == 2)
		move_player(data, data->x + 10, data->y);
	else if (keycode == 53)
		close_with();
	return (0);
}
