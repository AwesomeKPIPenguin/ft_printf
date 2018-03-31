/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:27:40 by domelche          #+#    #+#             */
/*   Updated: 2018/03/31 18:07:32 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(wchar_t wc, char *u_char, int size)
{
	if (size == 1)
	{
		u_char[0] = wc;
		return ;
	}
	u_char[size - 1] = 0x80 | (0x3F & wc);
	u_char[--size - 1] = 0xC0 | ((0xFC0 & wc) >> 6);
	if (--size)
		u_char[size - 1] = 0x80 | ((0x3F000 & wc) >> 12);
	if (--size)
		u_char[size - 1] = 0xF0 | ((0x3C0000 & wc) >> 18);
}

char		*ft_wctoa(wchar_t wc)
{
	char	*u_char;
	int		size;

	if (wc < 0x80)
		size = 1;
	else if (wc < 0x800)
		size = 2;
	else if (wc < 0x1000)
		size = 3;
	else if (wc < 0x110000)
		size = 4;
	if (!(u_char = (char *)ft_memalloc(4 * sizeof(char))))
		return (NULL);
	ft_convert(wc, u_char, size);
	return (u_char);
}
