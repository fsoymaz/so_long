#include "so_long.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		sign;

	size = ft_intlen(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	else
		sign = 1;
	while (size-- > (sign == -1))
	{
		result[size] = '0' + sign * (n % 10);
		n /= 10;
	}
	return (result);
}