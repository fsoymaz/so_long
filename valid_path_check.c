/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatihsoymaz <fatihsoymaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:38:03 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/15 12:16:56 by fatihsoymaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_duplicator(void)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (t_map.l_cnt + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (t_map.map[i])
	{
		copy[i] = ft_strdup(t_map.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	path_recursive(char **map, int c, int r)
{
	map[r][c] = '*';
	if (map[r + 1][c] != '1' && map[r + 1][c] != '*')
		path_recursive(map, c, r + 1);
	if (map[r - 1][c] != '1' && map[r - 1][c] != '*')
		path_recursive(map, c, r - 1);
	if (map[r][c + 1] != '1' && map[r][c + 1] != '*')
		path_recursive(map, c + 1, r);
	if (map[r][c - 1] != '1' && map[r][c - 1] != '*')
		path_recursive(map, c - 1, r);
}

int	path_checker(void)
{
	char	**map;
	int		j;
	int		i;

	map = map_duplicator();
	path_recursive(map, t_map.p_col, t_map.p_row);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' &&
			map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putstr("errormap\n");
				map_free(map);
				exit(0);
			}
		}
	}
	map_free(map);
	return (1);
}
