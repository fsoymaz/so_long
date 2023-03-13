/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:04:40 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/13 19:53:40 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./SRC/get_next_line/get_next_line.h"
# include <fcntl.h>
# include "./SRC/mlx/mlx.h"
# include <stdio.h>

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
	int		exit_col;
	int		exit_row;
	int		gate_col;
	int		gate_row;
	int		current_coin;
}	t_map;

typedef struct s_mlx
{
	char	*p_p;
	char	*w_p;
	char	*c_p;
	char	*g_p;
	char	*f_p;
	char	*m_p;

	int		x;
	int		y;

	int		x1;
	int		y1;

	char	*p;
	char	*w;
	char	*c;
	char	*g;
	char	*f;
	char	*m;

	int		a;
	int		b;

	void	*win;
	void	*init;
}	t_mlx;

int		close_with(void);
void	map_lines(char **argv);
char	**readmap(char **argv);
void	map_info(char **argv);
void	check_arg(char **argv);
void	check_map_chars(char c);
void	wall_check(char **argv);
void	wall_row_check(void);
int		ber_check(char **argv);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		path_checker(void);
char	**map_duplicator(void);
void	path_recursive(char **map, int c, int r);
void	xpm_to_img(t_mlx *map);
void	mlx_control(t_mlx *mlx);
void	put_img(t_mlx *mlx, char **map);
void	img_printer(t_mlx *mlx, char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	move_left(char **map, int *step);
void	exit_checker(t_mlx *mlx);
char	*ft_itoa(int n);
void	write_s(t_mlx *mlx, int step);

#endif