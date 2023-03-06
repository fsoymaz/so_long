/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:04:40 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/06 17:17:54 by fsoymaz          ###   ########.fr       */
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
	int		line_count;
}	t_map;

typedef struct s_data
{
}	t_data;

void	map_lines(void);
char	**readmap(void);

#endif