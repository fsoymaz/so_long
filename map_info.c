/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:27:30 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/03/08 14:46:06 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_lines(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	t_map.l_cnt = i;
	close(fd);
}

void	map_width(void)
{
	char	*line;
	int		fd;

	t_map.w_cnt = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	while (line[t_map.w_cnt])
		t_map.w_cnt++;
	t_map.w_cnt--;
}

char	**readmap(void)
{
	char	*str;
	int		i;
	int		fd;

	map_lines();
	t_map.map = malloc((t_map.l_cnt + 1) * sizeof(char *));
	if (!t_map.map)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	i = 0;
	while (t_map.l_cnt-- > 0)
	{
		str = get_next_line(fd);
		t_map.map[i++] = str;
	}
	t_map.map[i] = NULL;
	close(fd);
	return (t_map.map);
}

void	wall_check(void)
{
	int	i;
	int	j;

	map_lines();
	map_width();
	i = -1;
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j] && j < t_map.w_cnt)
		{
			if (t_map.map[i][0] != '1' || t_map.map[i][t_map.w_cnt - 1] != '1' \
			|| t_map.map[0][j] != '1' || t_map.map[t_map.l_cnt - 1][j] != '1')
			{
				write (2, "bitch", 5);
				exit(1);
			}
		}
	}
}

void	map_info(void)
{
	int	i;
	int	j;

	i = -1;
	readmap();
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
	wall_check();
}
