/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:04:40 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/09 17:46:34 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./SRC/get_next_line/get_next_line.h"
# include <fcntl.h>
# include "./SRC/mlx/mlx.h"

struct s_map
{
	char	**map;
	int		l_cnt;
	int		w_cnt;
	int		p_col;
	int		p_row;
	int		coin_count;
	int		chk_player;
	int		exit_count;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		i_h;
	int		i_w;
	int		x;
	int		y;
	char	**map;
}				t_data;

void	map_lines(char **argv);
char	**readmap(char **argv);
void	map_info(char **argv);
void	map_width(char **argv);
void	check_arg(char **argv);
void	check_map_chars(char c);
void	wall_check(char **argv);
void	wall_row_check(void);
int		ber_check(char **argv);
char	*ft_strchr(const char *s, int c);
int		key_hook(int keycode, t_data *data);
void	move_player(t_data *data, int x, int y);
int		close_with(void);
#endif