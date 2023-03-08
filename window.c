/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:39:12 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/07 19:25:08 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	close_with(void)
{
	exit(1);
	return (0);
}

void move_player(t_data *data, int x, int y) {
    data->x = x;
    data->y = y;
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
}

int key_hook(int keycode, t_data *data) {
    if (keycode == 13) // W tuşuna basıldı
        move_player(data, data->x, data->y - 10);
    else if (keycode == 0) // A tuşuna basıldı
        move_player(data, data->x - 10, data->y);
    else if (keycode == 1) // S tuşuna basıldı
        move_player(data, data->x, data->y + 10);
    else if (keycode == 2) // D tuşuna basıldı
        move_player(data, data->x + 10, data->y);
    else if (keycode == 53)
        close_with();
    return (0);
}


int main()
{
	t_data	data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 2000, 2000, "😀");
	data.path = "./xpms/player/player.xpm";
	data.img = mlx_xpm_file_to_image(data.mlx, data.path, &data.i_w, &data.i_h);
	data.x = 0;
	data.y = 0;
	data.map = NULL; // Map değişkenini başlangıçta NULL olarak ayarla
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);
	mlx_hook(data.win, 2, 1L << 0, &key_hook, &data); // klavye olaylarını işlemek için key_hook işlevini çağır
    mlx_hook(data.win, 17, 1L << 17, close_with, &data);
	mlx_loop(data.mlx);
	return (0);
}
