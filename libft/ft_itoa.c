/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:33:08 by domelche          #+#    #+#             */
/*   Updated: 2017/11/01 16:33:09 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	int				sign;
	int				i;
	char			*str;

	num = (n < 0) ? ((n + 1) * (-1) + 1) : n;
	len = ft_intlen(n);
	sign = (n < 0) ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1 + sign))))
		return (NULL);
	i = len - 1 + sign;
	str[len + sign] = 0;
	if (sign)
		str[0] = '-';
	while (i >= sign)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
