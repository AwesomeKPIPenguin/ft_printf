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
#include "itoa_basic.h"

char		*ft_itoa(long long num)
{
	unsigned long long	unum;
	int 				sign;

	if (num < 0)
	{
		unum = -1 * num;
		sign = 1;
	}
	else
	{
		unum = num;
		sign = 0;
	}
	return (ft_itoa_basic(unum, sign, 10));
}
