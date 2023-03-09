/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:16:30 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/09 16:59:08 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	char	n_c;

	n_c = (char)c;
	while (*s)
	{
		if (*s == n_c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (n_c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}