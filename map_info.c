/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:27:30 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/03/06 17:24:13 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_lines(void)
{
	char	*line;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	t_map.line_count = line_count;
}

char	**readmap(void)
{
	char	*str;
	int		i;
	int		fd;

	map_lines();
	t_map.map = malloc((t_map.line_count + 1) * sizeof(char *));
	if (!t_map.map)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	i = 0;
	while (t_map.line_count-- > 0)
	{
		str = get_next_line(fd);
		t_map.map[i++] = str;
	}
	t_map.map[i] = NULL;
	close(fd);
	return (t_map.map);
}

int	main(void)
{
	char	**map;
	int		i;

	readmap();
	i = 0;
	while (t_map.map[i])
	{
		printf("%s", t_map.map[i]);
		i++;
	}
	return (0);
}
