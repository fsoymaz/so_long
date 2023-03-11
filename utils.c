/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:16:30 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/03/11 01:33:29 by fsoymaz          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;
	char	*str;
	int		i;

	str = (char *)s1;
	len = 0;
	while (str[len])
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
