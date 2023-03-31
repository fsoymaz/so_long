/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:12 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/31 02:19:01 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_chars(char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != '\n')
	{
		ft_putstr("error: Invalid character in map.\n");
		exit(1);
	}
}

void	check_arg(char **argv)
{
	map_info(argv);
	if (t_map.chk_player != 1 || t_map.exit_count != 1 || t_map.coin_count == 0)
	{
		free(t_map.map);
		ft_putstr("error: number of arguments is not correct\n");
		exit(1);
	}
	wall_row_check();
}

void	wall_row_check(void)
{
	int	i;
	int	a;

	a = 0;
	while (a < t_map.l_cnt - 1)
	{
		i = ft_strlen(t_map.map[a]) - 1;
		if (i != t_map.w_cnt)
		{
			free(t_map.map);
			ft_putstr("error: lines are not equal in length\n");
			exit(1);
		}
		a++;
	}
	i = ft_strlen(t_map.map[a]);
	if (i != t_map.w_cnt)
	{
		ft_putstr("error: lines are not equal in length\n");
		exit(1);
	}
}

void	wall_check(char **argv)
{
	int	i;
	int	j;

	map_lines(argv);
	i = -1;
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j] && j < t_map.w_cnt)
		{
			if (t_map.map[i][0] != '1' || t_map.map[i][t_map.w_cnt - 1] != '1' \
			|| t_map.map[0][j] != '1' || t_map.map[t_map.l_cnt - 1][j] != '1')
			{
				ft_putstr("error: the walls are not complete\n");
				exit(1);
			}
		}
	}
}

int	ber_check(char **argv)
{
	char	*str;
	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
	{
		ft_putstr("error: file is not find\n");
		exit(1);
	}
	if (argv[1][5] == '.' && argv[1][6] != '.')
	{
		ft_putstr("error: this is a hidden ber file\n");
		exit(1);
	}
	else if (((ft_strcmp(str, ".ber") != 0) || ft_strlen(str) < 4))
	{
		ft_putstr("error:filename length not four or not .ber \n");
		exit(1);
	}
	return (0);
}