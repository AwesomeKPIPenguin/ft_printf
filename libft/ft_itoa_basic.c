/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:24:41 by domelche          #+#    #+#             */
/*   Updated: 2018/03/31 13:42:36 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	function ft_itoa_basic is strongly NOT recommended for straight usage,
**	because all validation is placed in "wrapping" functions, which are
**	recommended to use: ft_itoa, ft_itoa_base, ft_uitoa, ft_uitoa_base;
**	otherwise, in case of not valid arguments, undefined behavior is expected
*/

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

char		*ft_itoa_basic(unsigned long long num, int sign, int base)
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
