//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"

static char	*ft_strextract(char *str, int sign)
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (!str[i] && i < 31)
		i++;
	if (sign)
		str[--i] = '-';
	res = ft_strdup(&str[i]);
	free(str);
	return (res);
}

char 		*ft_itoa_basic(unsigned long long num, int sign, int base)
{
	int		i;
	char	*str;

	i = 31;
	str = (char *)ft_smemalloc(sizeof(char) * 33, "ft_itoa_basic");
	str[i] = '0';
	while (num)
	{
		str[i--] = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	return (ft_strextract(str, sign));
}
