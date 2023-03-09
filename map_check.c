/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:12 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/09 16:59:16 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_chars(char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != '\n')
	{
		write(2, "Invalid character in map.\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	check_arg(char **argv)
{
	map_info(argv);
	if (t_map.chk_player != 1 || t_map.exit_count != 1 || t_map.coin_count == 0)
	{
		write (2, "fazla arguman var\n", 18);
		exit(EXIT_FAILURE);
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
			write (2, "satırlar esit degil\n", 20);
			exit(1);
		}
		a++;
	}
	i = ft_strlen(t_map.map[a]);
	if (i != t_map.w_cnt)
	{
		write (2, "satırlar esit degil\n", 20);
		exit(1);
	}
}

void	wall_check(char **argv)
{
	int	i;
	int	j;

	map_lines(argv);
	map_width(argv);
	i = -1;
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j] && j < t_map.w_cnt)
		{
			if (t_map.map[i][0] != '1' || t_map.map[i][t_map.w_cnt - 1] != '1' \
			|| t_map.map[0][j] != '1' || t_map.map[t_map.l_cnt - 1][j] != '1')
			{
				write (2, "duvar bozuk\n", 12);
				exit(1);
			}
		}
	}
}

int	ber_check(char **argv)
{
	char	*str;

	str = ft_strchr(argv[1], '.');
	if (ft_strlen(str) != 4)
	{
		write (1, "hata\n", 5);
		exit(1);
	}
	if (str[0] == '.')
	{
		if (str[1] == 'b')
		{
			if (str[2] == 'e')
			{
				if (str[3] == 'r')
					return (1);
			}
		}
	}
	write (2, "map hata\n", 9);
	exit(1);
}
