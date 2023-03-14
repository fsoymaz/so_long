/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:27:30 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/03/14 14:17:47 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_lines(char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr("mapyok\n");
		free(line);
		exit(1);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	t_map.l_cnt = i;
	close(fd);
}

void	gate_finder(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				t_map.gate_col = j;
				t_map.gate_row = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	readmap(char **argv)
{
	char	*str;
	int		i;
	int		fd;

	map_lines(argv);
	t_map.map = malloc((t_map.l_cnt + 1) * sizeof(char *));
	if (!t_map.map)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (t_map.l_cnt-- > 0)
	{
		str = get_next_line(fd);
		t_map.map[i++] = str;
	}
	t_map.map[i] = NULL;
	gate_finder(t_map.map);
	close(fd);
	t_map.w_cnt = ft_strlen(t_map.map[0]) - 1;
}

void	map_info(char **argv)
{
	int	i;
	int	j;

	i = -1;
	readmap(argv);
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j])
		{
			if (t_map.map[i][j] == 'E')
				t_map.exit_count++;
			else if (t_map.map[i][j] == 'P')
			{
				t_map.chk_player++;
				t_map.p_col = j;
				t_map.p_row = i;
			}
			else if (t_map.map[i][j] == 'C')
				t_map.coin_count++;
			else
				check_map_chars(t_map.map[i][j]);
		}
	}
	wall_check(argv);
}
