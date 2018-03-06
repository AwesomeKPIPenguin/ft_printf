/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:55:04 by domelche          #+#    #+#             */
/*   Updated: 2017/11/04 11:55:05 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strextract(char *str, int sign)
{
	unsigned int	i;

	i = 0;
	while ((str[i] == '0' || !str[i]) && i < 31)
		i++;
	if (sign)
		str[--i] = '-';
	return (ft_strdup(&str[i]));
}

char		*ft_itoa_base(int n, int base)
{
	unsigned int	num;
	int				sign;
	int				i;
	char			*str;

	if (base < 2 || base > 16)
		return (NULL);
	num = (n < 0) ? ((n + 1) * (-1) + 1) : n;
	sign = (n < 0 && base == 10) ? 1 : 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * 33)))
		return (NULL);
	i = 31;
	while (i >= sign)
	{
		str[i--] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ft_strextract(str, sign));
}
