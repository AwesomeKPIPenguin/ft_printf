/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/04/13 16:03:36 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_arg	*ft_argnew()
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->prec = -1;
	return (arg);
}

int 	ft_isvalid_conv(char c)
{
	return (c == 's' || c == 'd' || c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' || c == 'X' || c == 'c' ||
			c == 'p' || c == '%' || c == 'D' || c == 'C' ||
			c == 'S' || c == 'O' || c == 'U');
}

int		ft_getconv(t_arg *arg, char conv)
{
	char	res;

	res = conv;
	if (ft_isvalid_conv(conv))
		res = (conv != 'X') ? ft_tolower(conv) : conv;
	if (ft_isupper(conv) && conv != 'X')
		arg->lflags |= LF_L;
	arg->flags &= ft_getmask(res);
	return (res);
}

char	*ft_getarg(t_arg *arg, char *format)
{
	format = ft_parse_flags(format, arg);
	arg->width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	if (*format == '.')
		arg->prec = ft_atoi(++format);
	while (ft_isdigit(*format))
		++format;
	format = ft_parse_lflags(format, arg);
	arg->conv = ft_getconv(arg, *format);
	if (arg->prec != -1 && arg->conv != 'c' && arg->conv != 's' &&
		arg->conv != '%')
		arg->flags &= ~F_ZERO;
	return (++format);
}
